#include "startupmenu.h"
#include "ui_startupmenu.h"

StartUpMenu::StartUpMenu(QWidget *parent, InformationDialog *informationDialog) :
    QDialog(parent),
    ui(new Ui::StartUpMenu)
{
    ui->setupUi(this);
    this->informationDialog = informationDialog;
}

StartUpMenu::~StartUpMenu()
{
    delete ui;
}

void StartUpMenu::on_simulateButton_clicked()
{
    emit sendIsTakingQuiz(false);
    this->close();
}


void StartUpMenu::on_quizButton_clicked()
{
    emit sendIsTakingQuiz(true);
    this->close();

}


void StartUpMenu::on_infoButton_clicked()
{
    informationDialog->exec();
}

void StartUpMenu::returnToMain() {
    this->exec();
}

