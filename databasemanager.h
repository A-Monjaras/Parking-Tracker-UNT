#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <QVariant>
#include <QVector>

class DatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();

    bool connect();
    void disconnect();

    QVector<QVector<QVariant>> executeQuery(const QString& query, const QMap<QString, QVariant>& params = QMap<QString, QVariant>());

    bool executeNonQuery(const QString& query);
    bool destroyDatabaseFile();

private:
    QSqlDatabase m_database;
};

#endif  // DATABASEMANAGER_H
