// dialog.cpp

#include "dialog.h"
#include "./ui_dialog.h"
#include <QQuickView>
#include <QQuickWidget>
#include <QQmlContext>

Dialog::Dialog(UserProfile* userProfile, CarProfile* carProfile, LicenseProfile* licenseProfile, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , m_userProfile(userProfile)
    , m_carProfile(carProfile)
    , m_licenseProfile(licenseProfile)
{
    ui->setupUi(this);
    QQuickView view;
    QQmlContext *context = ui->quickWidget->rootContext();


    context->setContextProperty("userProfile", m_userProfile);
    context->setContextProperty("carProfile", m_carProfile);
    context->setContextProperty("licenseProfile", m_licenseProfile);

    view.setSource(QUrl::fromLocalFile("main.qml"));
    view.show();

}

Dialog::~Dialog()
{
    delete ui;
}
