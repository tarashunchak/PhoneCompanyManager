#ifndef MESSAGECHECKER_H
#define MESSAGECHECKER_H
#include <QObject>
#include <QThread>

class MessageChecker : public QObject {
    Q_OBJECT

public:
    MessageChecker(QObject* parent = nullptr);
    ~MessageChecker();
    void setChatID(const uint);
    void startCheck();

signals:
    void new_message_detected();
    void cycle_finished();

private slots:
    void checkForNewMessages();

private:
    std::atomic<uint> last_message_id = 0u;
    std::atomic<uint> chat_id = 0u;
    QThread* thread;
};

#endif // MESSAGECHECKER_H
