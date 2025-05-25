QT       += core gui sql charts printsupport websockets

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
    customerspagefilter.cpp \
    customersreport.cpp \
    dashboard.cpp \
    dashboardseries.cpp \
    databasemanager.cpp \
    employeeschatpage.cpp \
    employeesdetailspage.cpp \
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
    requeststabelview.cpp \
    table_view_for_requestpage.cpp \
    tariffcard.cpp \
    tariffeditwidget.cpp \
    tariffspage.cpp \
    taskspage.cpp

HEADERS += \
    employeeschatpage.h \
    employeesdetailspage.h \
    includes/calculator.h \
    includes/customersreport.h \
    includes/employeesreport.h \
    includes/calculator.h \
    includes/chat.h \
    includes/comboboxdelegate.h \
    includes/authmanager.h \
    includes/barchart.h \
    includes/buttonsstylemanager.h \
    includes/currentuser.h \
    includes/customersdetailspage.h \
    includes/customerspage.h \
    includes/customersreport.h \
    includes/dashboard.h \
    includes/databasemanager.h \
    includes/employeespage.h \
    includes/employeesreport.h \
    includes/insertcustomerdialog.h \
    includes/insertemployeedialog.h \
    includes/inserttariffdialog.h \
    includes/loginpage.h \
    includes/mainwidget.h \
    includes/mainwindow.h \
    includes/messagebox.h \
    includes/navigationmanager.h \
    includes/pushbuttondelegate.h \
    includes/registrationmanager.h \
    includes/registrationpage.h \
    includes/report.h \
    includes/requestspage.h \
    includes/tariffcard.h \
    includes/tariffeditwidget.h \
    includes/tariffspage.h \
    includes/linechart.h \
    includes/passwordrecoverypage.h \
    includes/piechart.h \
    includes/taskspage.h \
    includes/insertcustomerdialog.h \
    includes/insertemployeedialog.h \
    includes/mainwidget.h \
    includes/messagebox.h \
    includes/pushbuttondelegate.h \
    includes/report.h \
    includes/tariffeditwidget.h \
    includes/taskspage.h \
    requeststabelview.h

FORMS += \
    employeeschatpage.ui \
    employeesdetailspage.ui \
    ui/calculator.ui \
    ui/insertcustomerdialog.ui \
    ui/insertemployeedialog.ui \
    ui/mainwidget.ui \
    ui/tariffeditwidget.ui \
    ui/taskspage.ui \
    ui/calculator.ui \
    ui/chat.ui \
    ui/customersdetailspage.ui \
    ui/customerspage.ui \
    ui/dashboard.ui \
    ui/employeespage.ui \
    ui/insertcustomerdialog.ui \
    ui/insertemployeedialog.ui \
    ui/inserttariffdialog.ui \
    ui/loginpage.ui \
    ui/mainwidget.ui \
    ui/mainwindow.ui \
    ui/passwordrecoverypage.ui \
    ui/registrationpage.ui \
    ui/requestspage.ui \
    ui/tariffcard.ui \
    ui/tariffeditwidget.ui \
    ui/tariffspage.ui \
    ui/taskspage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
