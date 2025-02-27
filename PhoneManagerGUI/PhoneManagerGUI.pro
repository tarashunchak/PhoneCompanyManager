QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buttonslogicmanager.cpp \
    buttonsshadowmanager.cpp \
    customerspage.cpp \
    dashboard.cpp \
    databasemanager.cpp \
    employeespage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    buttonslogicmanager.h \
    buttonsshadowmanager.h \
    customerspage.h \
    dashboard.h \
    databasemanager.h \
    employeespage.h \
    mainwindow.h

FORMS += \
    customerspage.ui \
    dashboard.ui \
    employeespage.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
