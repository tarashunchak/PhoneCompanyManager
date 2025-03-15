#ifndef INSERTTARIFFDIALOG_H
#define INSERTTARIFFDIALOG_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class InsertTariffDialog;
}

class InsertTariffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertTariffDialog(QWidget *parent = nullptr);
    ~InsertTariffDialog();

private slots:
    void InsertTariffToDB();

private: /*Methods*/
    void SetConnections()const;
    void ClearWidgets()const;

private:
    Ui::InsertTariffDialog *ui;

    QSqlDatabase* db;

};

#endif // INSERTTARIFFDIALOG_H
