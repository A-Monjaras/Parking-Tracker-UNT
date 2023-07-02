#include "License.h"

LicenseProfile::LicenseProfile(QObject *parent)
    : QObject(parent) {
}

QString LicenseProfile::licensePlate() const {
    return m_licensePlate;
}

void LicenseProfile::setLicensePlate(const QString &licensePlate) {
    if (licensePlate != m_licensePlate) {
        m_licensePlate = licensePlate;
        emit licensePlateChanged();
    }
}
