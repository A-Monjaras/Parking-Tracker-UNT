#include "loginpage.h"
#include <QPixmap>
#include <QMessageBox>
#include "ui_loginpage.h"


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

    QString stuNumber = "(940) 369-7392";
    ui->stuhdnum->setText("<a href=\"tel:" + stuNumber + "\">" + stuNumber + "</a>");
    ui->stuhdnum->setTextFormat(Qt::RichText);
    ui->stuhdnum->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->stuhdnum->setOpenExternalLinks(true);

    QString facNumber = "(940) 369-2324";
    ui->fachdnum->setText("<a href=\"tel:" + facNumber + "\">" + facNumber + "</a>");
    ui->fachdnum->setTextFormat(Qt::RichText);
    ui->fachdnum->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->fachdnum->setOpenExternalLinks(true);

    ui->idtextbox_password->setEchoMode(QLineEdit::Password);

    // Connect the showPassword button clicked signal to the togglePasswordVisibility slot
    connect(ui->showPassword, &QPushButton::clicked, this, &LoginPage::togglePasswordVisibility);
}

LoginPage::~LoginPage()
{
    delete ui;
}

QString LoginPage::hashPassword(const QString& password) {
    // Use a cryptographic hash function (e.g., SHA-256) to hash the password
    QByteArray passwordData = password.toUtf8();
    QByteArray hashedData = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256);

    // Convert the hashed data to a hexadecimal string
    QString hashedPassword = QString(hashedData.toHex());
    return hashedPassword;
}

void LoginPage::updatePasswordVisibility() {
    // Update the echo mode of the password line edit based on the state of the radio button
    if (ui->showPassword->isChecked()) {
        ui->idtextbox_password->setEchoMode(QLineEdit::Normal);
    } else {
        ui->idtextbox_password->setEchoMode(QLineEdit::Password);
    }
}

void LoginPage::togglePasswordVisibility() {
    // Invert the password visibility state and update the echo mode
    passwordVisible = !passwordVisible;
    if (passwordVisible) {
        ui->idtextbox_password->setEchoMode(QLineEdit::Normal);
    } else {
        ui->idtextbox_password->setEchoMode(QLineEdit::Password);
    }
}

void LoginPage::on_loginbutton_clicked()
{
    QString username = ui->idtextbox_username->text();
    QString password = ui->idtextbox_password->text();

    qDebug() << "Username:" << username;
    qDebug() << "Password:" << password;

    // Connect to the database
    if (!dbManager->connect()) {
        qDebug() << "Failed to connect to the database.";
        return;
    }

    //Hide the password with the hashing function
    QString hashedPassword = hashPassword(password);

    // Create the SQL query to select the user's data based on the euid (username) and password
    QString selectQuery = QString("SELECT * FROM users WHERE euid = '%1' AND password = '%2'")
                              .arg(username)
                              .arg(password);

    // Execute the query using the DatabaseManager instance
    QVector<QVector<QVariant>> result = dbManager->executeQuery(selectQuery);

    qDebug() << "Result Rows:" << result.size();

    // Check if the result contains any rows
    if (!result.isEmpty()) {
        // Login successful
        QMessageBox::information(this, "Login", "Login Successful");
        hide();

        // Get the singleton instance of UserDatabase
        UserDatabase* loggedInUser = UserDatabase::getInstance();
        loggedInUser->initializeUserData(
            result[0][0].toInt(),
            result[0][1].toString().toStdString(),
            result[0][2].toString().toStdString(),
            result[0][3].toString().toStdString(),
            result[0][4].toString().toStdString(),
            result[0][5].toString().toStdString(),
            result[0][6].toString().toStdString(),
            result[0][7].toString().toStdString(),
            result[0][8].toString().toStdString(),
            result[0][9].toString().toStdString(),
            result[0][10].toString().toStdString(),
            result[0][11].toString().toStdString(),
            result[0][12].toByteArray()
            );

        // Create an instance of MainWindow with the logged-in user's data
        MainWindow* main = new MainWindow(this);
        main->show();
    } else {
        // Login unsuccessful
        QMessageBox::warning(this, "Login", "Incorrect EUID or Password");
        ui -> idtextbox_password->clear();
    }
}
