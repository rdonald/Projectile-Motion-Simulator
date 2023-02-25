#ifndef INFORMATIONDIALOG_H
#define INFORMATIONDIALOG_H

#include <QDialog>

namespace Ui {
class InformationDialog;
}

class InformationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InformationDialog(QWidget *parent = nullptr);
    ~InformationDialog();

private slots:
    void on_cancelButton_clicked();

private:
    Ui::InformationDialog *ui;
};

#endif // INFORMATIONDIALOG_H
