#ifndef SPOTDATABASEMANAGER_H
#define SPOTDATABASEMANAGER_H

#include <QString>
#include <QVector>
#include <QVariant>
#include "databasemanager.h"
#include "parkingspot.h"

class SpotDatabaseManager {
public:
    SpotDatabaseManager(DatabaseManager* dbManager);

    QVector<ParkingSpot> getAllSpots();
    ParkingSpot getSpotById(int spotId);
    void updateSpotAvailability(int spotId, bool isAvailable);
    void saveCheckIn(int spotId, const QString& userId, const QDateTime& checkInTime);
    void saveCheckOut(int spotId, const QDateTime& checkOutTime);
    void assignUserToSpot(int spotId, const QString& userId);

    enum class UserType {
        Student,
        Faculty
    };

    // Parkingspot.h
    enum class SpotType {
        Student,
        Handicap,
        Faculty,
    };

private:
    DatabaseManager* m_dbManager;
};

#endif // SPOTDATABASEMANAGER_H
