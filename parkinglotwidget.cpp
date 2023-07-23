/*
#include "parkinglotwidget.h"
#include <QVBoxLayout>
#include <QLabel>

ParkingLotWidget::ParkingLotWidget(const Lot& lot, QWidget* parent)
    : QWidget(parent), m_lot(lot)
{
    QVBoxLayout* layout = new QVBoxLayout;

    QLabel* lotNameLabel = new QLabel(QString("Parking Lot: %1").arg(m_lot.getLotName()));
    layout->addWidget(lotNameLabel);

    // Implement the method to create and display the spot layout
    createLotLayout();

    setLayout(layout);
}

void ParkingLotWidget::createLotLayout()
{
    // Assuming your Lot class has a method to get the spot layout information, e.g., a 2D grid
    // Here, we assume a simple representation using a grid layout for demonstration purposes.
   /int numRows = m_lot.getNumRows();
    int numColumns = m_lot.getNumColumns();

    QGridLayout* gridLayout = new QGridLayout;

    // Create the parking spot widgets and add them to the grid layout
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numColumns; ++col) {
            ParkingSpot* spot = m_lot.getSpotAt(row, col);

            QLabel* spotLabel = new QLabel(QString("Spot %1").arg(spot->getSpotId()));
            spotLabel->setAlignment(Qt::AlignCenter);

            if (spot->isAvailable()) {
                spotLabel->setStyleSheet("background-color: green; color: white");
            } else {
                spotLabel->setStyleSheet("background-color: red; color: white");
            }

            gridLayout->addWidget(spotLabel, row, col);
        }
    }

    // Add the grid layout to the widget's layout
    layout()->addWidget(gridLayout);
}
*/
