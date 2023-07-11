#include "loginpage.h"
#include "ui_loginpage.h"
#include <QPixmap>
#include <QMessageBox>

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    //initialize the database
    dbManager = new DatabaseManager();

    ui->setupUi(this);

    QPixmap pix(":/img/unts-genericnewsimage_unt.png");
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

    qDebug() << "Username:" << username;
    qDebug() << "Password:" << password;

    // Create an instance of the DatabaseManager
    DatabaseManager dbManager;

    // Connect to the database
    if (!dbManager.connect()) {
        qDebug() << "Failed to connect to the database.";
        return;
    }

    // Create the SQL query to select the user's data based on the euid (username) and password
    QString selectQuery = QString("SELECT * FROM users WHERE euid = '%1' AND password = '%2'")
                              .arg(username)
                              .arg(password);

    // Execute the query using the DatabaseManager instance
    QVector<QVector<QVariant>> result = dbManager.executeQuery(selectQuery);

    qDebug() << "Result Rows:" << result.size();

    // Check if the result contains any rows
    if (!result.isEmpty()) {
        // Login successful
        QMessageBox::information(this, "Login", "Login Successful");
        hide();
        secDialog = new secondDialog(this);
        secDialog->show();
    } else {
        // Login unsuccessful
        QMessageBox::warning(this, "Login", "Login Failed");
    }
}
