#include "seconddialog.h"
#include <QLabel>

SecondDialog::SecondDialog(QWidget *parent) : QDialog(parent)
{
    createLayout();
}

SecondDialog::~SecondDialog()
{
    // Destructor code if needed
}

void SecondDialog::createLayout()
{
    mainLayout = new QVBoxLayout(this);

    // Create the table widget with 25 rows and 5 columns (excluding the "Directions" column)
    tableWidget = new QTableWidget(25, 5, this);
    mainLayout->addWidget(tableWidget);

    // Add table headers
    QStringList headerLabels = {"Lot Number", "Total Spots", "Available Spots", "Parking Type"};
    tableWidget->setHorizontalHeaderLabels(headerLabels);

    // Populate the table with sample data (you can replace this with your actual data)
    for (int row = 0; row < 25; ++row) {
        for (int col = 0; col < 4; ++col) {
            // Create a custom widget for each cell
            QWidget *widget = new QWidget();
            QHBoxLayout *cellLayout = new QHBoxLayout(widget);

            QLabel *label = new QLabel(QString("Row %1, Col %2").arg(row).arg(col));
            cellLayout->addWidget(label);

            cellLayout->setContentsMargins(0, 0, 0, 0);
            cellLayout->setSpacing(0);
            widget->setLayout(cellLayout);

            tableWidget->setCellWidget(row, col, widget);
        }

        // Add the "Get Directions" button for each row in the last column
        QPushButton *button = new QPushButton("Get Directions");
        connect(button, &QPushButton::clicked, [this, row]() { onGetDirectionsButtonClicked(row); });
        tableWidget->setCellWidget(row, 4, button);
    }

    // Set the header for the "Directions" column explicitly
    QTableWidgetItem *directionsHeader = new QTableWidgetItem("Directions");
    tableWidget->setHorizontalHeaderItem(4, directionsHeader);
}

void SecondDialog::onGetDirectionsButtonClicked(int row)
{
    // Handle the "Get Directions" button click for the specified row here
    qDebug() << "Get Directions clicked for row" << row;
}
