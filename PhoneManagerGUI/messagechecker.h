#ifndef MESSAGECHECKER_H
#define MESSAGECHECKER_H

#include <QObject>

extern "C"{
    #include <libpq-fe.h>
};

class MessageChecker : public QObject {
    Q_OBJECT
public:
    MessageChecker(QObject* parent = nullptr);
    ~MessageChecker() = default;
    void setChatID(const uint);

signals:
    void new_message_detected();

private slots:
    void checkForNewMessages();

private:
    std::atomic<uint> last_message_id = 0u;
    std::atomic<uint> chat_id = 0u;
};

#endif // MESSAGECHECKER_H
