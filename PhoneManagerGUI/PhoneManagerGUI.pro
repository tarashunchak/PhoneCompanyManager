QT       += core gui sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authmanager.cpp \
    barchart.cpp \
    buttonsstylemanager.cpp \
    currentuser.cpp \
    customersdetailspage.cpp \
    customerspage.cpp \
    dashboard.cpp \
    dashboard_barcharts.cpp \
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
    barchart.h \
    includes/authmanager.h \
    includes/buttonsstylemanager.h \
    includes/currentuser.h \
    includes/customersdetailspage.h \
    includes/customerspage.h \
    includes/dashboard.h \
    includes/databasemanager.h \
    includes/employeespage.h \
    includes/inserttariffdialog.h \
    includes/loginpage.h \
    includes/mainwindow.h \
    includes/navigationmanager.h \
    includes/registrationmanager.h \
    includes/registrationpage.h \
    includes/requestspage.h \
    includes/tariffcard.h \
    includes/tariffspage.h

FORMS += \
    customersdetailspage.ui \
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
