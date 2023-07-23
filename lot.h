#ifndef LOT_H
#define LOT_H

#include <vector>
#include <memory>
#include "parkingspot.h"

class Lot {
private:
    int lotId;
    std::string lotName;
    std::vector<std::shared_ptr<ParkingSpot>> spots;
    int totalSpots;
    std::string parkingType; // Faculty or Student

public:
    Lot(int lotId, const std::string& lotName, int totalSpots, const std::string& parkingType);

    Lot();

    int getLotId() const;
    std::string getLotName() const;
    int getTotalSpots() const;
    int getAvailableSpots() const;
    std::string getParkingType() const;

    void addSpot(std::shared_ptr<ParkingSpot> spot);
    void removeSpot(std::shared_ptr<ParkingSpot> spot);
    std::vector<std::shared_ptr<ParkingSpot>> getSpots() const;
};



#endif // LOT_H
