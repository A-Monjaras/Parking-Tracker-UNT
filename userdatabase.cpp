#include "userdatabase.h"



void UserDatabase::createTable() {
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name TEXT, "
               "dob TEXT, "
               "euid TEXT, "
               "password TEXT, "
               "email TEXT, "
               "type TEXT, "
               "carMake TEXT, "
               "carColor TEXT, "
               "carModel TEXT, "
               "carLicense TEXT, "
               "profilePic BLOB"
               ")");

}

void UserDatabase::createData()
{
    QSqlQuery query;

    // Create the users table (if it doesn't exist)
    createTable();

    // Inserting test data for user1
    QString insertQuery1 = "INSERT INTO users (name, dob, euid, password, email, type, carMake, carColor, carModel, carLicense, profilePic) "
                           "VALUES ('John Doe', '1980-01-01', '123456', 'password123', 'john@example.com', 'user', 'Honda', 'Red', 'Civic', 'ABC123', NULL)";
    if (!query.exec(insertQuery1)) {
        qDebug() << "Failed to insert test data for user1:" << query.lastError().text();
    }

    // Inserting test data for user2
    QString insertQuery2 = "INSERT INTO users (name, dob, euid, password, email, type, carMake, carColor, carModel, carLicense, profilePic) "
                           "VALUES ('Jane Smith', '1990-05-10', '654321', 'pass123', 'jane@example.com', 'user', 'Toyota', 'Blue', 'Corolla', 'XYZ789', NULL)";
    if (!query.exec(insertQuery2)) {
        qDebug() << "Failed to insert test data for user2:" << query.lastError().text();
    }

    // Inserting hardcoded user3
    QString insertQuery3 = "INSERT INTO users (name, dob, euid, password, email, type, carMake, carColor, carModel, carLicense, profilePic) "
                           "VALUES ('Emily Brown', '1995-08-15', '789012', 'pass456', 'emily@example.com', 'user', 'Ford', 'Black', 'Mustang', 'DEF456', NULL)";
    if (!query.exec(insertQuery3)) {
        qDebug() << "Failed to insert hardcoded data for user3:" << query.lastError().text();
    }

    if (query.isActive())
        query.finish(); // Finish the query execution

    qDebug() << "Test data inserted successfully!";
}

