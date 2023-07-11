#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <string>
#include <vector>
#include <databasemanager.h>>

class UserDatabase {
private:
    DatabaseManager* dbManager;
    int id;
    std::string name;
    std::string dob;
    std::string euid;
    std::string password;
    std::string email;
    std::string type;
    std::string carMake;
    std::string carModel;
    std::string carColor;
    std::string carLicense;
    std::vector<char> profilePic;
    

public:
    UserDatabase(DatabaseManager* dbManager, int id, const std::string& name, const std::string& dob, const std::string& euid, const std::string& password,
                 const std::string& email, const std::string& type, const std::string& carMake, const std::string& carModel,
                 const std::string& carColor, const std::string& carLicense, const std::vector<char>& profilePic)
        : dbManager(dbManager), id(id), name(name), dob(dob), euid(euid), password(password), email(email),
        type(type), carMake(carMake), carModel(carModel), carColor(carColor),
        carLicense(carLicense), profilePic(profilePic) {}


    // Stack Getter methods
    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getDob() const { return dob; }
    std::string getEuid() const { return euid; }
    std::string getPassword() const { return password; }
    std::string getEmail() const { return email; }
    std::string getType() const { return type; }
    std::string getCarMake() const { return carMake; }
    std::string getCarColor() const { return carColor; }
    std::string getCarModel() const { return carModel; }
    std::string getCarLicense() const { return carLicense; }
    std::vector<char> getProfilePic() const { return profilePic; }

    void createTable();
    void createData();

};

#endif  // USER_H
