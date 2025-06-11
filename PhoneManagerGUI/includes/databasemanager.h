#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "includes/currentuser.h"
#include "includes/chat.h"
#include "includes/messagebox.h"
#include "chat_type_traits.h"

class DatabaseManager
{
private:
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager();
    ~DatabaseManager();
    struct Columns{
        static QMap<QString, QStringList> columns;
    };
public:
    enum class PAGE : uint{
        DASHBOARD_PAGE = 0u,
        CUSTOMERS_PAGE,
        EMPLOYEES_PAGE,
        REQUESTS_PAGE,
        TARIFFS_PAGE,
        CHAT_PAGE,
        CUSTOMERS_DETAILS_PAGE,
        EMPLOYEES_DETAILS_PAGE,
        EMPLOYEES_CHATS_PAGE
    };
    enum class TABLE : uint{
        USERS = 0u,
        EMPLOYEES,
        CUSTOMERS,
        TARIFFS,
        REQUESTS,
        CHATS,
        CHAT_PARTICIPANTS,
        PARTICIPANTS,
        DEPATMENTS,
        POSITIONS,
        COMMENTS,
        MESSAGES,
        PAYMENTS,
        USAGE
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
    /*------------------------------------*/
    /*------------------------------------*/
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
    static void deleteRecord(TABLE, const uint);
    /*------------------------------------*/
    /*------------------------------------*/


    /*------------------------------------*/
    /*------------------------------------*/
    template <TABLE table, typename T> requires(
            table == TABLE::USERS
            &&
            typeid(T).name() == typeid(EmployeesChatPage).name()
            )
    static QSqlQuery findByName(const QString& text){

    }

    template <PAGE page> requires(page == PAGE::CHAT_PAGE)
    static MessageBox* lastMessage() {
        QSqlQuery query;
        query.prepare("SELECT * FROM messages "
                      "WHERE chat_id = :chat_id "
                      "ORDER BY id DESC LIMIT 1;");
        query.bindValue(":chat_id", Chat::ChatUnits::chat_id);
        if(!query.exec() || !query.next())
            return nullptr;
        MessageBox* message_box = new MessageBox{};
        message_box->SetMessageText(query.value("text").toString());
        message_box->SetMessageDateTime(query.value("timestamp").toString());
        return message_box;
    }

    template <typename T> requires(HasChatUnits<T>)
    static QSqlQuery allMessagesFromCurrentChat(){
        QSqlQuery query;
        query.prepare("SELECT * FROM messages WHERE chat_id = :chat_id;");
        query.bindValue(":chat_id", T::ChatUnits::chat_id);
        return query;
    }

    template <typename T> requires(HasChatUnits<T>)
    static bool initChatIfNeeded(){
        if(T::ChatUnits::chat_id == 0u){
            if(!insertToDB<TABLE::PARTICIPANTS, T>(false, T::ChatUnits::is_corporate)){
                qDebug() << "partner_participant is not inserted: ";
                return false;
            }
            if(!insertToDB<TABLE::PARTICIPANTS, T>(true, true)){
                qDebug() << "me_participant is not inserted: ";
                return false;
            }
            if(!insertToDB<TABLE::CHATS, T>(T::ChatUnits::is_corporate)){
                qDebug() << "chat is not inserted: ";
                return false;
            }
            if(!insertToDB<TABLE::CHAT_PARTICIPANTS, T>(true)){
                qDebug() << "chat_participant1 is not inserted: ";
                return false;
            }
            if(!insertToDB<TABLE::CHAT_PARTICIPANTS, T>(false)){
                qDebug() << "chat_participant2 is not inserted: ";
                return false;
            }
            T::ChatUnits::is_chat_exist = true;
            qDebug() << "/*------------------------------------*/";
            qDebug() << "NEW CHAT INSERTED : "
                     << "\nchat_id: " << T::ChatUnits::chat_id
                     << "\npartner_id: " << T::ChatUnits::partner_id
                     << "\npartner_participant_id: " << T::ChatUnits::partner_participant_id
                     << "\nmy_participant_id: " << T::ChatUnits::my_participant_id;
            qDebug() << "/*------------------------------------*/";
        }
        return true;
    };

    template <typename T> requires(HasChatUnits<T>)
    static void sendMessage(const QString& message_text){
        if(T::ChatUnits::chat_id == 0)
            if(!initChatIfNeeded<T>()) return;

        bool is_message_sended = insertToDB<TABLE::MESSAGES, T>(message_text);
        if(!is_message_sended)
            qDebug() << "sendMessage query error";
    };

    template <typename... Args>
    static bool insertToDB(TABLE table, const std::tuple<Args...> args){
        QString table_str = tableToString(table);
        int count = Columns::columns[table_str].size();
        QString place_holder{};
        for(int i = 0; i < count-1; ++i){
            place_holder += "?, ";
        }
        place_holder += "?";
        QString query_str = QString{"INSERT INTO %1 (%2) VALUES (%3);"}
                                .arg(table_str).arg(Columns::columns[table_str].join(", "))
                                .arg(place_holder);
        QSqlQuery query;
        query.prepare(query_str);
        std::apply([&query](const auto&... data){
            (..., query.addBindValue(data));
        }, args);
        return query.exec();
    };

    template <TABLE table, typename T> requires(HasChatUnits<T> && table == TABLE::MESSAGES)
    static bool insertToDB(const QString& message_text) {
        QSqlQuery query;
        query.prepare("INSERT INTO messages(text, sender_participant_id, chat_id) "
                      "VALUES(:text, :sender_id, :chat_id);");
        query.bindValue(":text", message_text);
        query.bindValue(":sender_id", T::ChatUnits::my_participant_id);
        query.bindValue(":chat_id", T::ChatUnits::chat_id);
        qDebug() << "insert messages my_id = " << T::ChatUnits::my_participant_id;
        return query.exec();
    }

    template <TABLE table, typename T> requires(HasChatUnits<T> && table == TABLE::CHATS)
    static bool insertToDB(bool is_corporate) {
        QSqlQuery query;
        query.prepare("INSERT INTO chats(is_corporate) "
                      "VALUES(:is_corp) RETURNING id;");
        query.bindValue(":is_corp", uint(is_corporate));
        if(query.exec() && query.next()){
            T::ChatUnits::chat_id = query.value("id").toUInt();
            qDebug() << "insert chats id: " << T::ChatUnits::chat_id;
            return true;
        }
        return false;
    };

    template <TABLE table, typename T> requires(HasChatUnits<T> && table == TABLE::PARTICIPANTS)
    static bool insertToDB(bool is_curr_user, bool is_employee) {
        static QString role;
        static uint id;

        if(is_employee)
            role = "employee";
        else
            role = "customer";
        if(is_curr_user)
            id = CurrentUser::getCurrentUserID();
        else
            id = T::ChatUnits::partner_id;

        QSqlQuery query;
        query.prepare("INSERT INTO participants (role, reference_id) "
                      "VALUES(:role, :ref_id) RETURNING id;");
        query.bindValue(":role", role);
        query.bindValue(":ref_id", id);
        if(query.exec() && query.next()){
            if(is_curr_user){
                T::ChatUnits::my_participant_id = query.value("id").toUInt();
                qDebug() << T::ChatUnits::my_participant_id;
            }else{
                T::ChatUnits::partner_participant_id = query.value("id").toUInt();
                qDebug() << T::ChatUnits::partner_participant_id;
            }
            qDebug() << "insert chats id: " << T::ChatUnits::chat_id;
            return true;
        }
        return false;
    };

    template <TABLE table, typename T> requires(HasChatUnits<T> && table == TABLE::CHAT_PARTICIPANTS)
    static bool insertToDB(bool is_curr_user) {
        uint id;
        if(is_curr_user)
            id = T::ChatUnits::my_participant_id;
        else
            id = T::ChatUnits::partner_participant_id;

        QSqlQuery query;
        query.prepare("INSERT INTO chat_participants (chat_id, participants_id) "
                      "VALUES(:chat_id, :part_id);");
        query.bindValue(":chat_id", T::ChatUnits::chat_id);
        query.bindValue(":part_id", id);
        qDebug() << "insert chats id: " << T::ChatUnits::chat_id;
        return query.exec();
    };
    /*------------------------------------*/
    /*------------------------------------*/

private:
    static QSqlDatabase db;
};


#endif // DATABASEMANAGER_H
