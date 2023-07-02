#include "CarProfile.h"

#include "CarProfile.h"

CarProfile::CarProfile(QObject *parent)
    : QObject(parent) {
}

QString CarProfile::model() const {
    return m_model;
}

QString CarProfile::color() const {
    return m_color;
}

void CarProfile::setModel(const QString &model) {
    if (model != m_model) {
        m_model = model;
        emit modelChanged();
    }
}

void CarProfile::setColor(const QString &color) {
    if (color != m_color) {
        m_color = color;
        emit colorChanged();
    }
}
