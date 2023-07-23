#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    UserDatabase* loggedInUser = UserDatabase::getInstance();

    QPixmap pix(":/img/unts-genericnewsimage_unt.png");
    QSize labelSize = ui->untlogo->size();
    QPixmap scaledPixmap = pix.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->untlogo->setPixmap(scaledPixmap);

    std::string euid = loggedInUser->getEuid();
    std::string userName = loggedInUser->getName();
    std::string userEmail = loggedInUser->getEmail();
    std::string userDob = loggedInUser->getDob();
    std::string userType = loggedInUser->getType();
    std::string carMake = loggedInUser->getCarMake();
    std::string carModel = loggedInUser->getCarModel();
    std::string carColor = loggedInUser->getCarColor();
    std::string carPlate = loggedInUser->getCarLicense();
    std::string carYear = loggedInUser->getCarYear();
    QByteArray profilePicData = loggedInUser->getProfilePicData();

    ui -> lineEdit->setText(QString::fromStdString(userName));
    ui -> lineEdit_2->setText(QString::fromStdString(userDob));
    ui -> lineEdit_3->setText(QString::fromStdString(userEmail));
    ui -> lineEdit_4->setText(QString::fromStdString(euid));
    ui -> lineEdit_5->setText(QString::fromStdString(userType));
    ui -> lineEdit_6->setText(QString::fromStdString(carMake));
    ui -> lineEdit_8->setText(QString::fromStdString(carModel));
    ui -> lineEdit_7->setText(QString::fromStdString(carColor));
    ui -> lineEdit_9->setText(QString::fromStdString(carPlate));
    ui -> lineEdit_10->setText(QString::fromStdString(carYear));

    // Convert the profilePicData to QPixmap
    QPixmap profilePixmap;
    profilePixmap.loadFromData(profilePicData);
   profilePixmap = profilePixmap.scaled(ui->profilePic->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->profilePic->setAlignment(Qt::AlignCenter);
    ui->profilePic->setPixmap(profilePixmap);

}


Dialog::~Dialog()
{
    delete ui;
}





