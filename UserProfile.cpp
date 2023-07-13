#include "userprofile.h"
#include <QObject>
#include "CarProfile.h"
#include "License.h"


UserProfile::UserProfile(QObject *parent)
  : QObject(parent), m_carProfile(new CarProfile(this)), m_licenseProfile(new LicenseProfile(this)) {}

QString UserProfile::name() const {
    return m_name;
}

QString UserProfile::id() const {
    return m_id;
}

CarProfile* UserProfile::carProfile() const {
    return m_carProfile;
}

LicenseProfile* UserProfile::licenseProfile() const {
    return m_licenseProfile;
}

QString UserProfile::pictureUrl() const {
    return m_pictureUrl;
}

void UserProfile::setName(const QString &name) {
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}

void UserProfile::setId(const QString &id) {
    if (id != m_id) {
        m_id = id;
        emit idChanged();
    }
}

void UserProfile::setPictureUrl(const QString &pictureUrl) {
    if (pictureUrl != m_pictureUrl) {
        m_pictureUrl = pictureUrl;
        emit pictureUrlChanged();
    }
}
