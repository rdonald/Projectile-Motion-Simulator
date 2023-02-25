/********************************************************************************
** Form generated from reading UI file 'startupmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUPMENU_H
#define UI_STARTUPMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StartUpMenu
{
public:
    QPushButton *infoButton;
    QPushButton *quizButton;
    QPushButton *simulateButton;
    QLabel *titleLabel;

    void setupUi(QDialog *StartUpMenu)
    {
        if (StartUpMenu->objectName().isEmpty())
            StartUpMenu->setObjectName(QString::fromUtf8("StartUpMenu"));
        StartUpMenu->resize(550, 439);
        infoButton = new QPushButton(StartUpMenu);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));
        infoButton->setGeometry(QRect(240, 370, 80, 21));
        quizButton = new QPushButton(StartUpMenu);
        quizButton->setObjectName(QString::fromUtf8("quizButton"));
        quizButton->setGeometry(QRect(240, 330, 80, 21));
        simulateButton = new QPushButton(StartUpMenu);
        simulateButton->setObjectName(QString::fromUtf8("simulateButton"));
        simulateButton->setGeometry(QRect(240, 290, 80, 21));
        titleLabel = new QLabel(StartUpMenu);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(100, 100, 331, 131));

        retranslateUi(StartUpMenu);

        QMetaObject::connectSlotsByName(StartUpMenu);
    } // setupUi

    void retranslateUi(QDialog *StartUpMenu)
    {
        StartUpMenu->setWindowTitle(QCoreApplication::translate("StartUpMenu", "Dialog", nullptr));
        infoButton->setText(QCoreApplication::translate("StartUpMenu", "Information", nullptr));
        quizButton->setText(QCoreApplication::translate("StartUpMenu", "Quiz", nullptr));
        simulateButton->setText(QCoreApplication::translate("StartUpMenu", "Simulate", nullptr));
        titleLabel->setText(QCoreApplication::translate("StartUpMenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">Projectile Simulator</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartUpMenu: public Ui_StartUpMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUPMENU_H
