#ifndef INSERTTARIFFDIALOG_H
#define INSERTTARIFFDIALOG_H

#include <QDialog>

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
    void setConnections();
    void clearWidgets()const;

private:
    Ui::InsertTariffDialog *ui;

};

#endif // INSERTTARIFFDIALOG_H
