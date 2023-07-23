#include "loginpage.h"
#include "userdatabase.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // Create an instance of the DatabaseManager
    DatabaseManager* dbManager = new DatabaseManager();

     dbManager->destroyDatabaseFile();

    // Connect to the database
    if (dbManager->connect()) {
        qDebug() << "Database connection established.";

        // Set the DatabaseManager instance directly in the UserDatabase class
        UserDatabase::setDatabaseManager(dbManager);

        // Get the singleton instance of the UserDatabase
        UserDatabase* userDb = UserDatabase::getInstance();

        // Create the users table
        userDb->createTable();

        // Insert the test data
        userDb->createData();

        // Retrieve the content of the users table
        QString selectQuery = "SELECT * FROM users";
        QVector<QVector<QVariant>> result = dbManager->executeQuery(selectQuery);

        /*
        // Display the table content in the console
        for (const QVector<QVariant>& row : result) {
            for (const QVariant& value : row) {
                qDebug() << value.toString();
            }
            qDebug() << "---------";
        }*/

        LoginPage loginPage;
        loginPage.show();

        int ret = a.exec();

        // Close the database connection before exiting the application
        dbManager->disconnect();
        delete dbManager; // Clean up the DatabaseManager instance.

        return ret;
    } else {
        qDebug() << "Failed to connect to the database.";
        // Handle the error appropriately.
        delete dbManager; // Clean up the DatabaseManager instance.
        return 1; // Exit the program due to the failed database connection.
    }
}
