#include "lot.h"

Lot::Lot(int lotId, const std::string& lotName, int totalSpots, const std::string& parkingType)
    : lotId(lotId), lotName(lotName), totalSpots(totalSpots), parkingType(parkingType) {}

int Lot::getLotId() const {
    return lotId;
}

std::string Lot::getLotName() const {
    return lotName;
}

int Lot::getTotalSpots() const {
    return totalSpots;
}

int Lot::getAvailableSpots() const {
    int availableSpots = 0;
    for (const auto& spot : spots) {
        if (spot->isAvailable()) {
            ++availableSpots;
        }
    }
    return availableSpots;
}

std::string Lot::getParkingType() const {
    return parkingType;
}

void Lot::addSpot(std::shared_ptr<ParkingSpot> spot) {
    spots.push_back(spot);
}

void Lot::removeSpot(std::shared_ptr<ParkingSpot> spot) {
    // Remove the spot from the spots vector, based on your implementation
    // ...
}

std::vector<std::shared_ptr<ParkingSpot>> Lot::getSpots() const {
    return spots;
}
