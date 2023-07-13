#include "seconddialog.h"
#include "ui_seconddialog.h"
#include <QPixmap>

secondDialog::secondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/img/unts-genericnewsimage_unt.png");
    ui -> untlogo2  ->setPixmap(pix.scaled(180,80));
    ui -> greentop2 -> setStyleSheet("background-color: #00853e;");
    ui -> whitebottom2 -> setStyleSheet("background-color: #white;");


    QPixmap pix2(":/img/untparkingmap.png");
    ui -> untparking  ->setPixmap(pix2.scaled(660,510));



}

secondDialog::~secondDialog()
{
    delete ui;
}


