#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "currentuser.h"
#include "supportchat.h"
#include "messagebox.h"
#include "chat_type_traits.h"
#include "databasesynchronizer.h"
#include "DB_ENUMS.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
private:
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager();
    ~DatabaseManager();
public:

    struct Columns{
        static QMap<QString, QStringList> columns;
        static QMap<QString, QStringList> all_columns;
    };

    static QString tableToString(TABLE);

    enum class ORDER : uint{
        ALL = 0u,
        ASC,
        DESC
    };
    //

    static DatabaseManager& instance();
    static QSqlDatabase& getDatabase();
    static bool isConnected();
    static void cleanUpConnections();
    static DatabaseSynchronizer* getSynchronizer();
    /*------------------------------------*/
    /*------------------------------------*/
    static void startSyncTables();
    static QSqlQuery findByName(TABLE, const QString&);
    static QSqlQuery inProgressRequests();
    static QSqlQuery unassignedRequests();
    static QSqlQuery completedRequests();
    static QSqlQuery requestsHistory(PAGE, QString period = {});
    static QSqlQuery departments();
    static QSqlQuery positions();
    static QSqlQuery MyAllCorporateChats();
    static QSqlQuery AllMessageFromSupportChat();
    static QSqlQuery newCustomersByPeriod(const bool, QString);
    static QSqlQuery newRequestsByPeriod(const bool, QString);
    static QSqlQuery currentCustomer(const uint);
    static QSqlQuery currentEmployee(const uint);
    static void saveCommentToDB(TABLE, int, int, const QString&);

    /*------------------------------------*/
    /*------------------------------------*/

    /*------------------------------------*/
    /*------------------------------------*/
    template <TABLE table, typename T>
    static QSqlQuery selectRecord(const QString& row, const T& identifier){
        static QString table_str = tableToString(table);
        QString query_str{"SELECT * FROM " + table_str
                + " WHERE " + row + " = ?;"};
        QSqlQuery query(local_db);
        query.prepare(query_str);
        query.addBindValue(identifier);
        return query;
    };

    template <TABLE table, typename T>
    static void deleteRecord(const QString& row, const T& identifier){
        static QString table_str = tableToString(table);
        QString query_str{"UPDATE " + table_str +
                          " SET is_visible = false "
                          " WHERE " + row + " = ?;"};
        QSqlQuery query(remote_db);
        query.prepare(query_str);
        query.addBindValue(identifier);
        query.exec();
    };

    template <PAGE page> requires(page == PAGE::SUPPORT_CHAT)
    static MessageBox* lastMessage() {
        QSqlQuery query(remote_db);
        query.prepare("SELECT * FROM messages "
                      "WHERE chat_id = ? "
                      "ORDER BY id DESC LIMIT 1;");
        query.addBindValue(SupportChat::ChatUnits::chat_id);
        qDebug() << "support chat_id = " << SupportChat::ChatUnits::chat_id;
        if(!query.exec() || !query.next())
            return nullptr;
        MessageBox* message_box = new MessageBox{};
        message_box->SetMessageText(query.value("text").toString());
        message_box->SetMessageDateTime(query.value("timestamp").toString());
        return message_box;
    }

    template <typename T> requires(HasChatUnits<T>)
    static QSqlQuery allMessagesFromCurrentChat(){
        QSqlQuery query(local_db);
        query.prepare("SELECT * FROM messages WHERE chat_id = ?;");
        query.addBindValue(T::ChatUnits::chat_id);
        return query;
    }

    template <typename T>
    static bool initChatIfNeeded(){
        if(T::ChatUnits::is_chat_exist == false){
            if constexpr(is_not_corporate<T>::value){
                if(!insertToDB<TABLE::PARTICIPANTS, T>(T::ChatUnits::is_corporate)){
                    qDebug() << "partner_participant is not inserted: " << T::ChatUnits::partner_id;
                    return false;
                }
            }
            if(!insertToDB<TABLE::CHATS, T>()){
                qDebug() << "chat is not inserted: ";
                return false;
            }
            if(!insertToDB<TABLE::CHAT_PARTICIPANTS, T>(true)){
                qDebug() << "me_chat_participant1 is not inserted: ";
                return false;
            }
            if(!insertToDB<TABLE::CHAT_PARTICIPANTS, T>(false)){
                qDebug() << "part_chat_participant is not inserted: ";
                return false;
            }
        }
        return true;
    };

    template <typename T> requires(HasChatUnits<T>)
    static void sendMessage(const QString& message_text){
        if(!initChatIfNeeded<T>()) return;

        bool is_message_sended = insertToDB<TABLE::MESSAGES, T>(message_text);

        if(!is_message_sended)
            qDebug() << "sendMessage query error";
        ;
    };

    template <typename... Args>
    static bool insertToDB(TABLE table, const std::tuple<Args...> args){
        QString table_str = tableToString(table);
        int count = Columns::columns[table_str].size();
        QString place_holder{};
        for(int i = 0; i < count - 1; ++i){
            place_holder += "?, ";
        }
        place_holder += "?";
        QString query_str = QString{"INSERT INTO %1 (%2) VALUES (%3);"}
                                .arg(table_str).arg(Columns::columns[table_str].join(", "))
                                .arg(place_holder);
        QSqlQuery query(remote_db);
        query.prepare(query_str);
        std::apply([&query](const auto&... data){
            (..., query.addBindValue(data));
        }, args);
        if (!remote_db.isOpen()) {
            if (!remote_db.open()) {
                qDebug() << "Database reopen failed: " << remote_db.lastError();
                return false;
            }
        }
        ;
        return query.exec();
    };

    template <TABLE table, typename T> requires(HasChatUnits<T> && table == TABLE::MESSAGES)
    static bool insertToDB(const QString& message_text) {
        QSqlQuery query(remote_db);
        query.prepare("INSERT INTO messages(text, sender_participant_id, chat_id) "
                      "VALUES(?, ?, ?);");
        query.addBindValue(message_text);
        query.addBindValue(T::ChatUnits::my_participant_id);
        query.addBindValue(T::ChatUnits::chat_id);
        qDebug() << "insert messages my_id = " << T::ChatUnits::my_participant_id;
        if (!remote_db.isOpen()) {
            if (!remote_db.open()) {
                qDebug() << "Database reopen failed: " << remote_db.lastError();
                return false;
            }
        }
        if(!query.exec()){
            return false;
        }
        ;
        return true;
    }

    template <TABLE table, typename T> requires(HasChatUnits<T> && table == TABLE::CHATS)
    static bool insertToDB() {
        static constexpr bool is_corp = is_corporate<T>::value;
        QSqlQuery query(remote_db);
        query.prepare("INSERT INTO chats(is_corporate) "
                      "VALUES(?) RETURNING id;");
        query.addBindValue(is_corp);
        ;
        if (!remote_db.isOpen()) {
            if (!remote_db.open()) {
                qDebug() << "Database reopen failed: " << remote_db.lastError();
                query.clear();
                return false;
            }
        }
        if(query.exec() && query.next()){
            T::ChatUnits::is_chat_exist = true;
            T::ChatUnits::chat_id = query.value("id").toUInt();
            qDebug() << "insert chats id: " << T::ChatUnits::chat_id;
            query.clear();
            return true;
        }
        query.clear();
        return false;
    };

    template <TABLE table, typename T> requires(HasChatUnits<T> && table == TABLE::PARTICIPANTS)
    static bool insertToDB(bool is_employee) {
        static QString role;
        static uint id;
        if(is_employee){
            role = "employee";
            id = CurrentUser::getCurrentUserID();
        }else{
            role = "customer";
            id = T::ChatUnits::partner_id;
        }
        QSqlQuery query(remote_db);
        query.prepare("INSERT INTO participants (role, reference_id) "
                      "VALUES(?, ?) RETURNING id;");
        query.addBindValue(role);
        query.addBindValue(id);
        if (!remote_db.isOpen()) {
            if (!remote_db.open()) {
                qDebug() << "Database reopen failed: " << remote_db.lastError();
                query.clear();
                return false;
            }
        }
        if(query.exec() && query.next()){
            T::ChatUnits::partner_participant_id = query.value("id").toUInt();
            qDebug() << T::ChatUnits::partner_participant_id;
            query.clear();
            return true;
        }
        query.clear();
        return false;
    };

    template <TABLE table, typename T> requires(HasChatUnits<T> && table == TABLE::CHAT_PARTICIPANTS)
    static bool insertToDB(bool is_curr_user) {
        uint id;
        if(is_curr_user)
            id = T::ChatUnits::my_participant_id;
        else
            id = T::ChatUnits::partner_participant_id;

        QSqlQuery query(remote_db);
        query.prepare("INSERT INTO chat_participants (chat_id, participants_id) "
                      "VALUES(?, ?);");
        query.addBindValue(T::ChatUnits::chat_id);
        query.addBindValue(id);
        qDebug() << "insert chats id: " << T::ChatUnits::chat_id;
        if (!remote_db.isOpen()) {
            if (!remote_db.open()) {
                qDebug() << "Database reopen failed: " << remote_db.lastError();
                return false;
            }
        }
        return query.exec();
    };
    /*------------------------------------*/
    /*------------------------------------*/
private:
    DatabaseSynchronizer syncronizer;
    static QSqlDatabase remote_db;
    static QSqlDatabase local_db;
};
#endif // DATABASEMANAGER_H
