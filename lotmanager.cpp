/*
#include "lotmanager.h"

LotManager::LotManager() = default; // Default constructor definition

void LotManager::addLot(const Lot& lot) {
    lots.push_back(lot);
}

Lot& LotManager::getLotById(int lotId) {
    for (Lot& lot : lots) {
        if (lot.getLotId() == lotId) {
            return lot;
        }
    }
    // Return a default Lot object if lotId is not found
    return emptyLot;
}

const std::vector<Lot>& LotManager::getAllLots() const {
    return lots;
}
*/
