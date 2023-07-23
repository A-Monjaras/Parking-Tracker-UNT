#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include "DatabaseManager.h"
#include "parkingdialog.h"
#include "userdatabase.h"
#include "mainwindow.h"
#include <QCryptographicHash>


QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    UserDatabase* loggedInUser;

private slots:
    void on_loginbutton_clicked();
    void togglePasswordVisibility();
    void updatePasswordVisibility();

private:
    Ui::LoginPage *ui;
    ParkingDialog *park;
    DatabaseManager* dbManager;
    MainWindow *main;
    bool passwordVisible = false;
    QString hashPassword(const QString& password);
};
#endif // LOGINPAGE_H
