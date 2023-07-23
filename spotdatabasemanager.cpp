#include "spotdatabasemanager.h"

SpotDatabaseManager::SpotDatabaseManager(DatabaseManager* dbManager)
    : m_dbManager(dbManager) {
}

QVector<ParkingSpot> SpotDatabaseManager::getAllSpots() {
    QVector<ParkingSpot> spots;

    // Retrieve spot data from the database and populate the spots vector
    QString query = "SELECT * FROM spots";
    QVector<QVector<QVariant>> result = m_dbManager->executeQuery(query);

    for (const auto& row : result) {
        int spotId = row[0].toInt();
        bool isAvailable = row[1].toBool();

        ParkingSpot spot(spotId, isAvailable, nullptr);  // Pass nullptr as the third argument
        spots.push_back(std::move(spot));
    }

    return spots;
}

ParkingSpot SpotDatabaseManager::getSpotById(int spotId) {
    // Retrieve spot data from the database based on the spotId
    QString query = "SELECT * FROM spots WHERE spot_id = :spotId";
    QMap<QString, QVariant> params;
    params[":spotId"] = spotId;

    QVector<QVector<QVariant>> result = m_dbManager->executeQuery(query);

    if (!result.isEmpty()) {
        // Extract spot data from the result and return a ParkingSpot object
        bool isAvailable = result[0][1].toBool();
        QString userId = result[0][2].toString();


        ParkingSpot spot(spotId, isAvailable, nullptr);
        return spot;
    }

    // Return an empty ParkingSpot object if the spot is not found
    //return ParkingSpot();
}

void SpotDatabaseManager::updateSpotAvailability(int spotId, bool isAvailable) {
    // Update the spot's availability in the database
    QString query = "UPDATE spots SET is_available = :isAvailable WHERE spot_id = :spotId";
    QMap<QString, QVariant> params;
    params[":isAvailable"] = isAvailable;
    params[":spotId"] = spotId;

    m_dbManager->executeNonQuery(query);
}

void SpotDatabaseManager::saveCheckIn(int spotId, const QString& userId, const QDateTime& checkInTime) {
    // Retrieve the user data from the database based on the user ID
    QString userQuery = "SELECT type FROM users WHERE euid = :userId";
    QMap<QString, QVariant> userParams;
    userParams[":userId"] = userId;

    QVector<QVector<QVariant>> userResult = m_dbManager->executeQuery(userQuery, userParams);

    if (!userResult.isEmpty()) {
        // Extract the user type from the result
        UserType userType = static_cast<UserType>(userResult[0][0].toInt());

        // Retrieve the spot data from the database based on the spot ID
        QString spotQuery = "SELECT is_available, spot_type FROM spots WHERE spot_id = :spotId";
        QMap<QString, QVariant> spotParams;
        spotParams[":spotId"] = spotId;

        QVector<QVector<QVariant>> spotResult = m_dbManager->executeQuery(spotQuery, spotParams);

        if (!spotResult.isEmpty()) {
            // Extract spot data from the result
            bool isAvailable = spotResult[0][0].toBool();
            SpotType spotType = static_cast<SpotType>(spotResult[0][1].toInt());

            // Check if the spot is available and the user is allowed to park there
            if (isAvailable && (userType == UserType::Student || spotType != SpotType::Faculty)) {
                // Perform the check-in process and update the database
                // ... implement the code to execute the SQL query and update the database
            } else {
                // The spot is not available or the user is not allowed to park there
                // Handle the error accordingly (e.g., show an error message to the user)
            }
        }
    }
}

void SpotDatabaseManager::saveCheckOut(int spotId, const QDateTime& checkOutTime) {
    // Save the check-out details in the database
    // ... implement the code to execute the SQL query and update the database
}

void SpotDatabaseManager::assignUserToSpot(int spotId, const QString& userId) {
    // Assign the user to the spot in the database
    // ... implement the code to execute the SQL query and update the database
}
