#include "mainwindow.h"
#include "startupmenu.h"
#include "informationdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InformationDialog informationDialog;
    StartUpMenu startUpMenu(nullptr, &informationDialog);
    MainWindow w(nullptr, &startUpMenu);
    startUpMenu.exec();
    w.show();
    return a.exec();
}
