#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>
#include "parkingdialog.h"

namespace Ui {
class secondDialog;
}

class secondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secondDialog(QWidget *parent = nullptr);
    ~secondDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::secondDialog *ui;
    ParkingDialog *park;
};

#endif // SECONDDIALOG_H
