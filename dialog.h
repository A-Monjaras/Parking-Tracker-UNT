#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "UserProfile.h"
#include "CarProfile.h"
#include "License.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(UserProfile* userProfile, CarProfile* carProfile, LicenseProfile* licenseProfile, QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    UserProfile* m_userProfile;
    CarProfile* m_carProfile;
    LicenseProfile* m_licenseProfile;
};

#endif // DIALOG_H
