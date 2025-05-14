#ifndef INSERTCUSTOMERDIALOG_H
#define INSERTCUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class InsertCustomerDialog;
}

class InsertCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertCustomerDialog(QWidget *parent = nullptr);
    ~InsertCustomerDialog();
    void updateComboBoxData();
    void InsertCustomerToDB();

private:
    Ui::InsertCustomerDialog *ui;
};

#endif // INSERTCUSTOMERDIALOG_H
