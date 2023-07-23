#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <string>
#include <vector>
#include <databasemanager.h>

class UserDatabase {
private:

    static UserDatabase* instance; // Static member to hold the singleton instance.
    static DatabaseManager* dbManager; // Static member to hold the DatabaseManager pointer.

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
    std::string carYear;
    QByteArray profilePicData;


    UserDatabase() {}


public:
    // Set the DatabaseManager instance in the singleton class.
    static void setDatabaseManager(DatabaseManager* dbManager) {
        UserDatabase::dbManager = dbManager;
    }

    // Static function to get the singleton instance.
    static UserDatabase* getInstance() {
        if (instance == nullptr) {
            instance = new UserDatabase();
        }
        return instance;
    }

    ~UserDatabase() {
        name.clear();
        dob.clear();
        euid.clear();
        password.clear();
        email.clear();
        type.clear();
        carMake.clear();
        carModel.clear();
        carColor.clear();
        carLicense.clear();
        carYear.clear();
        profilePicData.clear();
    }



    // Initialize the user data after the singleton instance is created.
    void initializeUserData(int id, const std::string& name, const std::string& dob, const std::string& euid,
                            const std::string& password, const std::string& email, const std::string& type,
                            const std::string& carMake, const std::string& carModel,
                            const std::string& carColor, const std::string& carLicense,
                            const std::string& carYear,
                            const QByteArray& profilePicData) {
        this->id = id;
        this->name = name;
        this->dob = dob;
        this->euid = euid;
        this->password = password;
        this->email = email;
        this->type = type;
        this->carMake = carMake;
        this->carModel = carModel;
        this->carColor = carColor;
        this->carLicense = carLicense;
        this->carYear = carYear;
        this->profilePicData = profilePicData;
    }


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
    std::string getCarYear() const { return carYear; }
    QByteArray getProfilePicData() const { return profilePicData; }

    void createTable();
    void createData();

    // Delete the copy constructor and assignment operator to prevent cloning.
    UserDatabase(const UserDatabase&) = delete;
    UserDatabase& operator=(const UserDatabase&) = delete;


};




// Initialize the static member instance to nullptr.
static UserDatabase* instance;

// Initialize the static member dbManager to nullptr.
static DatabaseManager* dbManager;

#endif  // USERDATABASE_H
