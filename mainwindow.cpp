#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ProfileButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    acc = new Dialog(this);
    acc->show();
}


void MainWindow::on_MapButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    sec=new secondDialog(this);
          sec->show();
}


void MainWindow::on_LotTableButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
          park = new ParkingDialog(this);
    park->show();
}


void MainWindow::on_pushButtonPermit_clicked()
{
    permit = new PermitPage(this);
    permit->show();
}

