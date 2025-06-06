#ifndef INSERTEMPLOYEEDIALOG_H
#define INSERTEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class InsertEmployeeDialog;
}

class InsertEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertEmployeeDialog(QDialog *parent = nullptr);
    ~InsertEmployeeDialog();
    void InsertEmployeeToDB();
    void updateComboBoxData();

private:
    void clearWidgets();

private:
    Ui::InsertEmployeeDialog *ui;
};

#endif // INSERTEMPLOYEEDIALOG_H
