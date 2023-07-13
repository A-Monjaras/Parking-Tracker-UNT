#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <QObject>
#include <QString>
#include "CarProfile.h"
#include "License.h"

class UserProfile : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(CarProfile* carProfile READ carProfile CONSTANT)
    Q_PROPERTY(LicenseProfile* licenseProfile READ licenseProfile CONSTANT)
    Q_PROPERTY(QString pictureUrl READ pictureUrl WRITE setPictureUrl NOTIFY pictureUrlChanged)

public:
    UserProfile(QObject *parent = nullptr);

    QString name() const;
    QString id() const;
    CarProfile* carProfile() const;
    LicenseProfile* licenseProfile() const;
    QString pictureUrl() const;

    void setName(const QString &name);
    void setId(const QString &id);
    void setPictureUrl(const QString &pictureUrl);

signals:
    void nameChanged();
    void idChanged();
    void pictureUrlChanged();

private:
    QString m_name;
    QString m_id;
    CarProfile* m_carProfile;
    LicenseProfile* m_licenseProfile;
    QString m_pictureUrl;
};

#endif // USERPROFILE_H
