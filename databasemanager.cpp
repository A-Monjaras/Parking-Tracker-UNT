#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() {
    // Initialize member variables
}

DatabaseManager::~DatabaseManager() {
    // Cleanup and close the database connection
    disconnect();
}

bool DatabaseManager::connect() {
    // Remove any existing connection with the same name
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        m_database = QSqlDatabase::database("qt_sql_default_connection");
        m_database.close();
    }

    // Connect to the database using appropriate connection parameters
    m_database = QSqlDatabase::addDatabase("QSQLITE", "qt_sql_default_connection");
    m_database.setDatabaseName("database.db");

    if (!m_database.open()) {
        // Handle error if connection fails
        return false;
    }

    return true;
}

void DatabaseManager::disconnect() {
    // Close the database connection
    m_database.close();
}

#include <QFile>

bool DatabaseManager::destroyDatabaseFile() {
    disconnect(); // Close the database connection before deleting the file

    // Get the database file name
    QString databaseFileName = "database.db";

    // Check if the database file exists
    if (QFile::exists(databaseFileName)) {
        // Attempt to remove the database file
        if (QFile::remove(databaseFileName)) {
            qDebug() << "Old database file removed successfully.";
            return true;
        } else {
            qWarning() << "Failed to remove the old database file.";
            return false;
        }
    } else {
        qDebug() << "The old database file does not exist.";
        return true; // Consider this as a successful operation since the old file doesn't exist.
    }
}


QVector<QVector<QVariant>> DatabaseManager::executeQuery(const QString& query, const QMap<QString, QVariant>& params) {
    QVector<QVector<QVariant>> result;

    QSqlQuery sqlQuery;
    sqlQuery.prepare(query);

    for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
        sqlQuery.bindValue(it.key(), it.value());
    }

    if (sqlQuery.exec()) {
        while (sqlQuery.next()) {
            QVector<QVariant> row;
            for (int i = 0; i < sqlQuery.record().count(); ++i) {
                row.append(sqlQuery.value(i));
            }
            result.append(row);
        }
    }

    return result;
}


bool DatabaseManager::executeNonQuery(const QString& query) {
    QSqlQuery sqlQuery(query);

    if (sqlQuery.exec()) {
        return true;
    } else {
        // Handle error if query execution fails
        return false;
    }
}
