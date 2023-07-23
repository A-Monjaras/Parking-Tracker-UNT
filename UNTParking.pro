QT += core gui

greaterThan(QT_MAJOR_VERSION, 4):

QT += widgets
CONFIG += c++17
QT += sql





SOURCES += \
    databasemanager.cpp \
    parkinglotwidget.cpp \
    permitpage.cpp \
    lot.cpp \
    lotmanager.cpp \
    main.cpp \
    loginpage.cpp \
    mainwindow.cpp \
    parkingspot.cpp \
    seconddialog.cpp \
    dialog.cpp \
    parkingdialog.cpp \
    spotdatabasemanager.cpp \
    userdatabase.cpp


HEADERS += \
    WebSocketServer.h \
    databasemanager.h \
    mapfile.h \
    parkinglotwidget.h \
    permitpage.h \
    loginpage.h \
    lot.h \
    lotmanager.h \
    mainwindow.h \
    parkingspot.h \
    seconddialog.h \
    dialog.h \
    parkingdialog.h \
    spotdatabasemanager.h \
    userdatabase.h


FORMS += \
    loginpage.ui \
    mainwindow.ui \
    seconddialog.ui \
    dialog.ui \
    parkingdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    logo.qrc

DISTFILES +=
