/*
#ifndef PARKINGLOTWIDGET_H
#define PARKINGLOTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "lot.h"

class ParkingLotWidget : public QWidget {
    Q_OBJECT

public:
    ParkingLotWidget(const Lot& lot, QWidget* parent = nullptr);

private:
    Lot m_lot;
    QGridLayout* m_layout;

    // You can customize this widget to display the spots according to the lot layout
    void createLotLayout();
};

#endif // PARKINGLOTWIDGET_H

*/
