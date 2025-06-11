#include "includes/employeespage.h"
#include "ui_employeespage.h"
#include <QSqlError>

void EmployeesPage::updateFilterWidgets(){
    //fillTariffsComboBox();
    //fillEmployeesComboBox();
}

/*void EmployeesPage::fillTariffsComboBox(){
    QSqlQuery query;
    query.prepare("SELECT * FROM tariffs;");
    if(!query.exec()){
        qDebug() << "fillTariffsComboBox() query fault!";
        return;
    }
    ui->tariffs_comboBox->clear();
    ui->tariffs_comboBox->addItem("All", "");
    while(query.next()){
        ui->tariffs_comboBox->addItem(query.value("tariff_name").toString(),
                                      " tariff_id = " + query.value("id").toString());
    }
}

void EmployeesPage::fillEmployeesComboBox(){
    QSqlQuery query;
    query.prepare("SELECT id, "
                  "(COALESCE(first_name, '') "
                  "|| ' ' || "
                  "COALESCE(last_name, '') "
                  "|| ' ' || ' ID(' || id || ')') AS full_name "
                  "FROM employees;");

    if(!query.exec()){
        qDebug() << "fillEmployeesComboBox() query fault!";
        return;
    }
    ui->employees_comboBox->clear();
    ui->employees_comboBox->addItem("All", "");
    while(query.next()){
        ui->employees_comboBox->addItem(query.value("full_name").toString(),
                                        " employee_id = " + query.value("id").toString());
    }
}*/

void EmployeesPage::close_filter_widget(){
    ui->lineEdit->setGeometry(1300, 23, 290, 30);
    ui->close_open_filter_btn->setGeometry(1590, 23, 30, 30);
    filter_animation->setEndValue(QPoint{1670, 0});
    filter_animation->start();
}

void EmployeesPage::open_filter_widget(){
    ui->lineEdit->setGeometry(1060, 23, 290, 30);
    ui->close_open_filter_btn->setGeometry(1350, 23, 30, 30);
    filter_animation->setEndValue(QPoint{1390, 0});
    updateFilterWidgets();
    filter_animation->start();
}

void EmployeesPage::open_close_filter_widget(){
    filter_animation->setStartValue(QPoint{1670, 0});
    if(ui->filter_widget->x() == 1670)
        open_filter_widget();
    else
        close_filter_widget();
}

void EmployeesPage::apply_filters(){
    static QString tariff_id;
    static QString empl_id;
    static QString order_by;
    static QString phone;
    empl_id = ui->employees_comboBox->currentData().toString();
    tariff_id = ui->tariffs_comboBox->currentData().toString();
    order_by = ui->sort_by_comboBox->currentData().toString();

    if(ui->number_comboBox->currentIndex())
        phone = ui->number_comboBox->currentText() + "%";
    else
        phone = "";

    QString query_str{"SELECT * FROM employees "};
    //if(!empl_id.isEmpty()) query_str += " AND " + empl_id;
    //if(!tariff_id.isEmpty()) query_str += " AND " + tariff_id;
    //if(!phone.isEmpty()) query_str += " AND phone LIKE :phone";
    query_str += order_by;

    QSqlQuery query;
    query.prepare(query_str);
    //query.bindValue(":phone", phone);

    if(!query.exec())
        qDebug() << "apply filters fault: " << query.lastError();
    SetEmployeesCards(std::move(query));
}
