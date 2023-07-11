#include "DatabaseManager.h"

DatabaseManager::DatabaseManager() {
    // Initialize member variables
}

DatabaseManager::~DatabaseManager() {
    // Cleanup and close the database connection
    disconnect();
}

bool DatabaseManager::connect() {
    // Connect to the database using appropriate connection parameters
    m_database = QSqlDatabase::addDatabase("QSQLITE");
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

QVector<QVector<QVariant>> DatabaseManager::executeQuery(const QString& query) {
    QVector<QVector<QVariant>> result;

    QSqlQuery sqlQuery(query);

    if (sqlQuery.exec()) {
        while (sqlQuery.next()) {
            QVector<QVariant> row;
            for (int i = 0; i < sqlQuery.record().count(); ++i) {
                row.append(sqlQuery.value(i));
            }
            result.append(row);
        }
    } else {
        // Handle error if query execution fails
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


