#ifndef MESSAGECHECKER_H
#define MESSAGECHECKER_H
#include <QObject>
#include <QThread>

class MessageChecker : public QObject {
    Q_OBJECT

private:
    MessageChecker(QObject* parent = nullptr);
    ~MessageChecker();
    MessageChecker& operator=(const MessageChecker&) = default;
public:
    void startCheck();
    static const MessageChecker* getChecker();

signals:
    void new_message_detected();
    void cycle_finished();
    void notify_employee();

private slots:
    void checkForNewMessages();

private:
    std::atomic<uint> last_message_id = 0u;
    QThread* thread;
};

#endif // MESSAGECHECKER_H
