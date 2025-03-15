QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authmanager.cpp \
    buttonsstylemanager.cpp \
    currentuser.cpp \
    customerspage.cpp \
    dashboard.cpp \
    databasemanager.cpp \
    employeespage.cpp \
    inserttariffdialog.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    navigationmanager.cpp \
    registrationmanager.cpp \
    registrationpage.cpp \
    requestspage.cpp \
    tariffcard.cpp \
    tariffspage.cpp

HEADERS += \
    authmanager.h \
    buttonsstylemanager.h \
    currentuser.h \
    customerspage.h \
    dashboard.h \
    databasemanager.h \
    employeespage.h \
    inserttariffdialog.h \
    loginpage.h \
    mainwindow.h \
    navigationmanager.h \
    registrationmanager.h \
    registrationpage.h \
    requestspage.h \
    tariffcard.h \
    tariffspage.h

FORMS += \
    customerspage.ui \
    dashboard.ui \
    employeespage.ui \
    inserttariffdialog.ui \
    loginpage.ui \
    mainwindow.ui \
    registrationpage.ui \
    requestspage.ui \
    tariffcard.ui \
    tariffspage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
