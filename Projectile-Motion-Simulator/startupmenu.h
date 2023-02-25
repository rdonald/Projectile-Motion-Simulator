#ifndef STARTUPMENU_H
#define STARTUPMENU_H

#include <QDialog>
#include "informationdialog.h"
//#include "mainwindow.h"

namespace Ui {
class StartUpMenu;
}

class StartUpMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StartUpMenu(QWidget *parent = nullptr, InformationDialog *informationDialog = nullptr);
    InformationDialog *informationDialog = nullptr;
    ~StartUpMenu();
signals:
    void sendIsTakingQuiz(bool);

public slots:
    void returnToMain();

private slots:
    void on_simulateButton_clicked();

    void on_quizButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::StartUpMenu *ui;
};

#endif // STARTUPMENU_H
