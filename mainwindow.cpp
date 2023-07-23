#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    park(nullptr), // Initialize to nullptr
    acc(nullptr),  // Initialize to nullptr
    permit(nullptr), // Initialize to nullptr
    sec(nullptr) // Initialize to nullptr
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ProfileButton_clicked()
{
    ui->MainWindowView;

    acc = new Dialog(this);
    acc->show();

}


void MainWindow::on_MapButton_clicked()
{
    ui->MainWindowView;
    sec = new SecondDialog(this);
          sec->show();
}


void MainWindow::on_LotTableButton_clicked()
{
    ui->MainWindowView;
    park = new ParkingDialog(this);
    park->show();
}


void MainWindow::on_pushButtonPermit_clicked()
{
    permit = new PermitPage(this);
    permit->show();
}

