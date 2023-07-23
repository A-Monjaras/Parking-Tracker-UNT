#ifndef LOTMANAGER_H
#define LOTMANAGER_H

#include <vector>
#include "lot.h"

class LotManager {
public:
    LotManager(); // Default constructor

    void addLot(const Lot& lot);
    Lot& getLotById(int lotId);
    const std::vector<Lot>& getAllLots() const; // Getter for lots

private:
    std::vector<Lot> lots;
    Lot emptyLot;  // Default Lot object for error handling or default returns
};

#endif // LOTMANAGER_H
