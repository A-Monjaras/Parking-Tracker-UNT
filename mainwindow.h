#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "parkingdialog.h"
#include "dialog.h"
#include "permitpage.h"
#include "seconddialog.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsView>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ProfileButton_clicked();

    void on_MapButton_clicked();

    void on_LotTableButton_clicked();

    void on_pushButtonPermit_clicked();

private:
    Ui::MainWindow *ui;
    ParkingDialog *park;
    Dialog *acc;
    PermitPage *permit;
    SecondDialog *sec;
};

#endif // MAINWINDOW_H
