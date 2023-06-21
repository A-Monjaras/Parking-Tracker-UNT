#include "seconddialog.h"
#include "ui_seconddialog.h"
#include <QPixmap>

secondDialog::secondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondDialog)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/aldom/Desktop/3444Files/unts-genericnewsimage_unt.png");
    ui -> untlogo2  ->setPixmap(pix.scaled(180,80));
    ui -> greentop2 -> setStyleSheet("background-color: #00853e;");
    ui -> whitebottom2 -> setStyleSheet("background-color: #white;");



}

secondDialog::~secondDialog()
{
    delete ui;
}
