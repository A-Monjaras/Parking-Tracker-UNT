#ifndef LICENSE_H
#define LICENSE_H

#include <QObject>
#include <QString>

class LicenseProfile : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString licensePlate READ licensePlate WRITE setLicensePlate NOTIFY licensePlateChanged)

public:
    explicit LicenseProfile(QObject *parent = nullptr);

    QString licensePlate() const;
    void setLicensePlate(const QString &licensePlate);

signals:
    void licensePlateChanged();

private:
    QString m_licensePlate;
};

#endif // LICENSE_H
