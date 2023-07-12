#ifndef PARKINGDIALOG_H
#define PARKINGDIALOG_H


#include <QDialog>

namespace Ui {
class ParkingDialog;
}

class ParkingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParkingDialog(QWidget *parent = nullptr);
    ~ParkingDialog();

private slots:
    void on_backButton_clicked();

private:
    Ui::ParkingDialog *ui;

};

#endif // PARKINGDIALOG_H
