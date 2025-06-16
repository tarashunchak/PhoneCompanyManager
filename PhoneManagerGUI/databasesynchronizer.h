#ifndef DATABASESYNCHRONIZER_H
#define DATABASESYNCHRONIZER_H
#include <QObject>
#include <QThread>
#include "DB_ENUMS.h"

class DatabaseSynchronizer : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseSynchronizer(QObject* parent = nullptr);
    ~DatabaseSynchronizer();

    void startSync(const QList<TABLE>&);
    void syncAllTables();
signals:
    void sync_finished();
    void update_info();

private:
    QThread* thread;
    QList<TABLE> tables;
};

#endif // DATABASESYNCHRONIZER_H
