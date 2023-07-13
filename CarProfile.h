#ifndef CARPROFILE_H
#define CARPROFILE_H

#include <QObject>
#include <QString>

class CarProfile : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString model READ model WRITE setModel NOTIFY modelChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)

public:
    explicit CarProfile(QObject *parent = nullptr);

    QString model() const;
    QString color() const;

    void setModel(const QString &model);
    void setColor(const QString &color);

signals:
    void modelChanged();
    void colorChanged();

private:
    QString m_model;
    QString m_color;
};

#endif // CARPROFILE_H
