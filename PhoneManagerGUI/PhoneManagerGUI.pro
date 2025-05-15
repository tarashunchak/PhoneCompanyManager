QT       += core gui sql charts printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authmanager.cpp \
    barchart.cpp \
    buttonsstylemanager.cpp \
    calculator.cpp \
    chat.cpp \
    comboboxdelegate.cpp \
    currentuser.cpp \
    customersdetailspage.cpp \
    customerspage.cpp \
    customersreport.cpp \
    dashboard.cpp \
    dashboardseries.cpp \
    databasemanager.cpp \
    employeespage.cpp \
    employeesreport.cpp \
    insertcustomerdialog.cpp \
    insertemployeedialog.cpp \
    inserttariffdialog.cpp \
    linechart.cpp \
    loginpage.cpp \
    main.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    messagebox.cpp \
    navigationmanager.cpp \
    passwordrecoverypage.cpp \
    piechart.cpp \
    pushbuttondelegate.cpp \
    registrationmanager.cpp \
    registrationpage.cpp \
    report.cpp \
    requestspage.cpp \
    table_view_for_requestpage.cpp \
    tariffcard.cpp \
    tariffeditwidget.cpp \
    tariffspage.cpp \
    taskspage.cpp

HEADERS += \
    calculator.h \
    customersreport.h \
    employeesreport.h \
    includes/chat.h \
    includes/comboboxdelegate.h \
    includes/authmanager.h \
    includes/barchart.h \
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
    includes/tariffspage.h \
    includes/linechart.h \
    includes/passwordrecoverypage.h \
    includes/piechart.h \
    insertcustomerdialog.h \
    insertemployeedialog.h \
    mainwidget.h \
    messagebox.h \
    pushbuttondelegate.h \
    report.h \
    tariffeditwidget.h \
    taskspage.h

FORMS += \
    calculator.ui \
    insertcustomerdialog.ui \
    insertemployeedialog.ui \
    mainwidget.ui \
    tariffeditwidget.ui \
    taskspage.ui \
    ui/chat.ui \
    ui/customersdetailspage.ui \
    ui/customerspage.ui \
    ui/dashboard.ui \
    ui/employeespage.ui \
    ui/inserttariffdialog.ui \
    ui/loginpage.ui \
    ui/mainwindow.ui \
    ui/passwordrecoverypage.ui \
    ui/registrationpage.ui \
    ui/requestspage.ui \
    ui/tariffcard.ui \
    ui/tariffspage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
