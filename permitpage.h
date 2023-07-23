#ifndef PERMITPAGE_H
#define PERMITPAGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PermitPage; }
QT_END_NAMESPACE

class PermitPage : public QMainWindow
{
    Q_OBJECT

public:
    PermitPage(QWidget *parent = nullptr);
    ~PermitPage();

private slots:
    void on_VehicleInfo_clicked();

    void on_UpdateVehicle_clicked();

private:
    Ui::PermitPage *ui;
};
#endif // PERMITPAGE_H
