#include "permitpage.h"
#include "./ui_permitpage.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

PermitPage::PermitPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PermitPage)
{
    ui->setupUi(this);
    ui->VehicleInfo->setText("Vehicle Information");
    ui->UpdateVehicle->setText("Update Vehicle");
    this->setStyleSheet("background-color:  white;");




}

PermitPage::~PermitPage()
{
    delete ui;
}


void PermitPage::on_VehicleInfo_clicked()
{

}


void PermitPage::on_UpdateVehicle_clicked()
{

}

