#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include <QString>
#include "userdatabase.h"

class ParkingSpot {
public:
    ParkingSpot(int spotId, bool isAvailable, UserDatabase* userDb);

    // Getters
    int getSpotId() const;
    bool isAvailable() const;
    QString getUserId() const;
    bool isStudent() const;
    bool isStaff() const;

    // Setters
    void setAvailable(bool available);
    void setUserId(const QString& userId);

    // Other functions
    void checkIn(const QString& userId);
    void checkOut();

private:
    int m_spotId;
    bool m_isAvailable;
    QString m_userId;
    UserDatabase* m_userDb;
};

#endif // PARKINGSPOT_H
