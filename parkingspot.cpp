#include "parkingspot.h"

ParkingSpot::ParkingSpot(int spotId, bool isAvailable, UserDatabase* userDb)
    : m_spotId(spotId), m_isAvailable(isAvailable), m_userDb(userDb) {}

UserDatabase* loggedInUser = UserDatabase::getInstance();

int ParkingSpot::getSpotId() const {
    return m_spotId;
}

bool ParkingSpot::isAvailable() const {
    return m_isAvailable;
}



bool ParkingSpot::isStudent() const {
    // Retrieve user information from the UserDatabase
    std::string userType = loggedInUser->getType();

    // Check if the user is a student based on their type
    return (userType == "student");
}

bool ParkingSpot::isStaff() const {
    // Retrieve user information from the UserDatabase
    std::string userType = loggedInUser->getType();

    // Check if the user is staff based on their type
    return (userType == "staff");
}


void ParkingSpot::setAvailable(bool available) {
    m_isAvailable = available;
}

void ParkingSpot::setUserId(const QString& userId) {
    m_userId = userId;
}

void ParkingSpot::checkIn(const QString& userId) {
    m_isAvailable = false;
    m_userId = userId;
    // Perform necessary operations with UserDatabase to update user check-in status
    // ...
}

void ParkingSpot::checkOut() {
    m_isAvailable = true;
    m_userId.clear();
    // Perform necessary operations with UserDatabase to update user check-out status
    // ...
}
