#include "loginpage.h"
#include "userdatabase.h"
#include "databasemanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Initialize the database manager
    DatabaseManager dbManager;
    if (!dbManager.connect()) {
        // Handle error if database connection fails
        return -1;
    }

    // Create the user database object
    UserDatabase userDb(&dbManager, 0, "", "", "", "", "", "", "", "", "", "", {});

    // Create the users table (if it doesn't exist)
    userDb.createTable();

    // Insert the test data
    userDb.createData();


    // Assuming you have an instance of the DatabaseManager named dbManager

    // Retrieve the content of the users table
    QString selectQuery = "SELECT * FROM users";
    QVector<QVector<QVariant>> result = dbManager.executeQuery(selectQuery);

    // Display the table content in the console
    for (const QVector<QVariant>& row : result) {
        for (const QVariant& value : row) {
            qDebug() << value.toString();
        }
        qDebug() << "---------";
    }


    LoginPage w;
    w.show();

    return a.exec();
}
