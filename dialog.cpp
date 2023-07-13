#include "dialog.h"
#include "./ui_dialog.h"




Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pix(":/img/unts-genericnewsimage_unt.png");
    ui -> untlogo  ->setPixmap(pix.scaled(180,80));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ChangeText(){
    ui->lineEdit->setText("will");

}




