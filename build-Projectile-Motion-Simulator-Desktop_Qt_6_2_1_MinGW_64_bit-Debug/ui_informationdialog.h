/********************************************************************************
** Form generated from reading UI file 'informationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATIONDIALOG_H
#define UI_INFORMATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InformationDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *cancelButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QLabel *infoLabel;
    QLabel *infoLabel2;
    QLabel *infoLabel3;
    QLabel *infoLabel4;
    QLabel *infoLabel5;
    QLabel *infoLabel6;
    QLabel *infoLabel7;
    QLabel *infoLabel8;
    QLabel *infoLabel9;
    QLabel *infoLabel10;
    QLabel *infoLabel11;
    QLabel *infoLabel12;
    QLabel *infoLabel13;
    QLabel *infoLabel14;
    QLabel *infoLabel15;
    QLabel *infoLabel16;
    QLabel *infoLabel17;
    QLabel *infoLabel18;

    void setupUi(QDialog *InformationDialog)
    {
        if (InformationDialog->objectName().isEmpty())
            InformationDialog->setObjectName(QString::fromUtf8("InformationDialog"));
        InformationDialog->resize(410, 291);
        gridLayout = new QGridLayout(InformationDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cancelButton = new QPushButton(InformationDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout->addWidget(cancelButton, 1, 1, 1, 1);

        scrollArea = new QScrollArea(InformationDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, -31, 741, 261));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        infoLabel = new QLabel(scrollAreaWidgetContents_2);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));

        verticalLayout->addWidget(infoLabel);

        infoLabel2 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel2->setObjectName(QString::fromUtf8("infoLabel2"));
        infoLabel2->setIndent(10);

        verticalLayout->addWidget(infoLabel2);

        infoLabel3 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel3->setObjectName(QString::fromUtf8("infoLabel3"));
        infoLabel3->setIndent(20);

        verticalLayout->addWidget(infoLabel3);

        infoLabel4 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel4->setObjectName(QString::fromUtf8("infoLabel4"));
        infoLabel4->setIndent(20);

        verticalLayout->addWidget(infoLabel4);

        infoLabel5 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel5->setObjectName(QString::fromUtf8("infoLabel5"));
        infoLabel5->setIndent(10);

        verticalLayout->addWidget(infoLabel5);

        infoLabel6 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel6->setObjectName(QString::fromUtf8("infoLabel6"));
        infoLabel6->setIndent(20);

        verticalLayout->addWidget(infoLabel6);

        infoLabel7 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel7->setObjectName(QString::fromUtf8("infoLabel7"));
        infoLabel7->setIndent(20);

        verticalLayout->addWidget(infoLabel7);

        infoLabel8 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel8->setObjectName(QString::fromUtf8("infoLabel8"));
        infoLabel8->setIndent(20);

        verticalLayout->addWidget(infoLabel8);

        infoLabel9 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel9->setObjectName(QString::fromUtf8("infoLabel9"));
        infoLabel9->setIndent(20);

        verticalLayout->addWidget(infoLabel9);

        infoLabel10 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel10->setObjectName(QString::fromUtf8("infoLabel10"));
        infoLabel10->setIndent(20);

        verticalLayout->addWidget(infoLabel10);

        infoLabel11 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel11->setObjectName(QString::fromUtf8("infoLabel11"));
        infoLabel11->setIndent(20);

        verticalLayout->addWidget(infoLabel11);

        infoLabel12 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel12->setObjectName(QString::fromUtf8("infoLabel12"));
        infoLabel12->setIndent(20);

        verticalLayout->addWidget(infoLabel12);

        infoLabel13 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel13->setObjectName(QString::fromUtf8("infoLabel13"));
        infoLabel13->setIndent(20);

        verticalLayout->addWidget(infoLabel13);

        infoLabel14 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel14->setObjectName(QString::fromUtf8("infoLabel14"));
        infoLabel14->setIndent(10);

        verticalLayout->addWidget(infoLabel14);

        infoLabel15 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel15->setObjectName(QString::fromUtf8("infoLabel15"));
        infoLabel15->setIndent(20);

        verticalLayout->addWidget(infoLabel15);

        infoLabel16 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel16->setObjectName(QString::fromUtf8("infoLabel16"));
        infoLabel16->setIndent(20);

        verticalLayout->addWidget(infoLabel16);

        infoLabel17 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel17->setObjectName(QString::fromUtf8("infoLabel17"));
        infoLabel17->setIndent(20);

        verticalLayout->addWidget(infoLabel17);

        infoLabel18 = new QLabel(scrollAreaWidgetContents_2);
        infoLabel18->setObjectName(QString::fromUtf8("infoLabel18"));
        infoLabel18->setIndent(20);

        verticalLayout->addWidget(infoLabel18);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 2);


        retranslateUi(InformationDialog);

        QMetaObject::connectSlotsByName(InformationDialog);
    } // setupUi

    void retranslateUi(QDialog *InformationDialog)
    {
        InformationDialog->setWindowTitle(QCoreApplication::translate("InformationDialog", "Dialog", nullptr));
        cancelButton->setText(QCoreApplication::translate("InformationDialog", "Cancel", nullptr));
        infoLabel->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">Information:</span></p></body></html>", nullptr));
        infoLabel2->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Main Menu:</span></p></body></html>", nullptr));
        infoLabel3->setText(QCoreApplication::translate("InformationDialog", "Selecting Simulate will allow you to use the simulator freely.", nullptr));
        infoLabel4->setText(QCoreApplication::translate("InformationDialog", "Selecting Quiz will begin the quiz.", nullptr));
        infoLabel5->setText(QCoreApplication::translate("InformationDialog", "Simulate/Quiz", nullptr));
        infoLabel6->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>Selecting the Fire button will shoot the cannon with the current values and simulate the trajectory of the projectile.</p></body></html>", nullptr));
        infoLabel7->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>Selecting the Reset button will reset the simulator to the default values of the cannon.</p></body></html>", nullptr));
        infoLabel8->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>Selecting the Main Menu button will show the Main Menu again.</p></body></html>", nullptr));
        infoLabel9->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>Selecting the Formula Page button will display the basic formulas of projectile motion.</p></body></html>", nullptr));
        infoLabel10->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>Selecting Gravity in the simulation screen will allow the user to change the value of the gravity used in the simulator.</p></body></html>", nullptr));
        infoLabel11->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>Selecting Initial Velocity in the simulation screen will allow the user to change the value of the initial velocity of the projectile used in the simulator.</p></body></html>", nullptr));
        infoLabel12->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>Selecting Height in the simulation screen will allow the user to change the value of the height of the cannon used in the simulator.</p></body></html>", nullptr));
        infoLabel13->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>Selecting Angle in the simulation screen will allow the user to change the value of the angle of the cannon used in the simulator.</p></body></html>", nullptr));
        infoLabel14->setText(QCoreApplication::translate("InformationDialog", "Quiz Only:", nullptr));
        infoLabel15->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>These options are only available in Quiz mode: </p></body></html>", nullptr));
        infoLabel16->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>Selecting the Reset Quiz button will reset the quiz to the first question.</p></body></html>", nullptr));
        infoLabel17->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>Selecting the Submit button will submit you current choice to see if it is correct.</p></body></html>", nullptr));
        infoLabel18->setText(QCoreApplication::translate("InformationDialog", "<html><head/><body><p>If the selected answer is incorrect will display a hint while selecting the correct question will move the quiz to the next question after a short delay.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InformationDialog: public Ui_InformationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATIONDIALOG_H
