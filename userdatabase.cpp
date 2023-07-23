#include "userdatabase.h"
#include <QFile>
#include <QByteArray>

UserDatabase* UserDatabase::instance = nullptr;
DatabaseManager* UserDatabase::dbManager = nullptr;



//Reading the Profile picture then putting it into the SQL database per the
//SQL documentation

QByteArray readImageFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open the image file:" << file.errorString();
        return QByteArray();
    }

    QByteArray data = file.readAll();
    file.close();
    return data;
}


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
               "carYear TEXT, "
               "profilePic BLOB"
               ")");

}

void UserDatabase::createData()
{
    // Create the users table (if it doesn't exist)
    createTable();

    QSqlQuery query;

    // Load profile picture data for user1
    QByteArray profilePicDataUser1 = readImageFile(":/img/defaultProfilePic.jpg");
    if (profilePicDataUser1.isEmpty()) {
        qDebug() << "Failed to load profile picture data for user1.";
        return;
    }

    // Inserting test data for user1 with custom profile picture
    QString insertQuery1 = "INSERT INTO users (name, dob, euid, password, email, type, carMake, carColor, carModel, carLicense, carYear, profilePic) "
                           "VALUES ('Ryker Valnes', '09-19-2001', 'rjv0053', 'Rvalnes1', 'valnesr@gmail.com', 'Student', 'Buick', 'White', 'Encore', 'JSP-875', '2015', :profilePicData)";
    query.prepare(insertQuery1);
    query.bindValue(":profilePicData", profilePicDataUser1);
    if (!query.exec()) {
        qDebug() << "Failed to insert test data for user1:" << query.lastError().text();
    }

    // Load profile picture data for user2
    QByteArray profilePicDataUser2 = readImageFile(":/img/clemPic.jpg");
    if (profilePicDataUser2.isEmpty()) {
        qDebug() << "Failed to load profile picture data for user2.";
        return;
    }

    // Inserting test data for user2 with custom profile picture
    QString insertQuery2 = "INSERT INTO users (name, dob, euid, password, email, type, carMake, carColor, carModel, carLicense, carYear, profilePic) "
                           "VALUES ('Clementine Valnes', '04-03-2023', 'cjv7894', 'meowmeow', 'clementine@example.com', 'Student', 'Toyota', 'Blue', 'Corolla', 'XYZ789', '2012', :profilePicData)";
    query.prepare(insertQuery2);
    query.bindValue(":profilePicData", profilePicDataUser2);
    if (!query.exec()) {
        qDebug() << "Failed to insert test data for user2:" << query.lastError().text();
    }

    // Load profile picture data for user3
    QByteArray profilePicDataUser3 = readImageFile(":/img/vincentPic.jpg");
    if (profilePicDataUser3.isEmpty()) {
        qDebug() << "Failed to load profile picture data for user3.";
        return;
    }

    // Inserting hardcoded user3 with custom profile picture
    QString insertQuery3 = "INSERT INTO users (name, dob, euid, password, email, type, carMake, carColor, carModel, carLicense, carYear, profilePic) "
                           "VALUES ('Vincent Alvarez', '03-13-2022', 'vma3325', 'breow', 'vinnie@example.com', 'Staff', 'Ford', 'Black', 'Mustang', 'DEF456', '2000' , :profilePicData)";
    query.prepare(insertQuery3);
    query.bindValue(":profilePicData", profilePicDataUser3);
    if (!query.exec()) {
        qDebug() << "Failed to insert hardcoded data for user3:" << query.lastError().text();
    }

    qDebug() << "Test data inserted successfully!";
}


