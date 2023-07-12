#include "loginpage.h"
#include "ui_loginpage.h"
#include <QPixmap>
#include <QMessageBox>

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    QPixmap pix(":/img/Images/unts-genericnewsimage_unt.png");
    ui -> untlogo  ->setPixmap(pix);
    ui->greenTop->setStyleSheet("background-color: #00853e;");
    ui->whiteBack->setStyleSheet("background-color: white;");

    ui->manageID->setText("<a href=\"https://ams.untsystem.edu/\">Manage EUID and password</a>");
    ui->manageID->setTextFormat(Qt::RichText);
    ui->manageID->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->manageID->setOpenExternalLinks(true);

    QString stuNumber= "(940) 369-7392";
    ui->stuhdnum->setText("<a href=\"tel:" + stuNumber  + "\">" + stuNumber + "</a>");
    ui->stuhdnum->setTextFormat(Qt::RichText);
    ui->stuhdnum->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->stuhdnum->setOpenExternalLinks(true);

    QString facNumber= "(940) 369-2324";
    ui->fachdnum->setText("<a href=\"tel:" + facNumber + "\">" + facNumber+ "</a>");
    ui->fachdnum->setTextFormat(Qt::RichText);
    ui->fachdnum->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->fachdnum->setOpenExternalLinks(true);


}

LoginPage::~LoginPage()
{
    delete ui;
}


void LoginPage::on_loginbutton_clicked()
{
    QString username = ui->idtextbox_username->text();
    QString password = ui->idtextbox_password->text();

    if(username == "test" && password == "test")
    {
        QMessageBox::information(this,"Login","Login Successful");
        hide();
        main = new MainWindow(this);
        main->show();
    }
    else
    {
        QMessageBox::warning(this,"Login","Login Failed");
    }
}

