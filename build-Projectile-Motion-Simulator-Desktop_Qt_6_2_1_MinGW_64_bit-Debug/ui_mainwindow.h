/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *simulationImageLabel;
    QLabel *questionLabel;
    QPushButton *fireButton;
    QToolBox *slidersBox;
    QWidget *gravityPage;
    QSlider *gravitySlider;
    QSpinBox *gravitySpinBox;
    QWidget *initialVelocityPage;
    QSlider *initialVelocitySlider;
    QSpinBox *initialVelocitySpinBox;
    QWidget *heightPage;
    QSlider *heightSlider;
    QSpinBox *heightSpinBox;
    QWidget *anglePage;
    QSlider *angleSlider;
    QSpinBox *angleSpinBox;
    QRadioButton *choice1Button;
    QRadioButton *choice2Button;
    QRadioButton *choice3Button;
    QRadioButton *choice4Button;
    QLabel *tipLabel;
    QLabel *questionNumberLabel;
    QPushButton *resetButton;
    QLabel *cannonLabel;
    QLabel *groundLabel;
    QLabel *cannonBallLabel;
    QPushButton *submitButton;
    QPushButton *formulaButton;
    QPushButton *resetQuizButton;
    QPushButton *mainButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 900);
        MainWindow->setStyleSheet(QString::fromUtf8("QLabel {background-color: rgb(255, 255, 255);}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        simulationImageLabel = new QLabel(centralwidget);
        simulationImageLabel->setObjectName(QString::fromUtf8("simulationImageLabel"));
        simulationImageLabel->setGeometry(QRect(0, 0, 1590, 500));
        simulationImageLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 216, 230)\n"
""));
        questionLabel = new QLabel(centralwidget);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));
        questionLabel->setGeometry(QRect(20, 650, 1291, 31));
        fireButton = new QPushButton(centralwidget);
        fireButton->setObjectName(QString::fromUtf8("fireButton"));
        fireButton->setGeometry(QRect(490, 570, 91, 31));
        slidersBox = new QToolBox(centralwidget);
        slidersBox->setObjectName(QString::fromUtf8("slidersBox"));
        slidersBox->setGeometry(QRect(1077, 20, 171, 200));
        slidersBox->setStyleSheet(QString::fromUtf8("QSpinBox {color: green;}"));
        gravityPage = new QWidget();
        gravityPage->setObjectName(QString::fromUtf8("gravityPage"));
        gravityPage->setGeometry(QRect(0, 0, 171, 92));
        gravitySlider = new QSlider(gravityPage);
        gravitySlider->setObjectName(QString::fromUtf8("gravitySlider"));
        gravitySlider->setGeometry(QRect(0, 0, 160, 16));
        gravitySlider->setMinimum(1);
        gravitySlider->setValue(10);
        gravitySlider->setOrientation(Qt::Horizontal);
        gravitySpinBox = new QSpinBox(gravityPage);
        gravitySpinBox->setObjectName(QString::fromUtf8("gravitySpinBox"));
        gravitySpinBox->setGeometry(QRect(20, 30, 42, 22));
        gravitySpinBox->setMinimum(1);
        gravitySpinBox->setValue(10);
        slidersBox->addItem(gravityPage, QString::fromUtf8("Gravity"));
        initialVelocityPage = new QWidget();
        initialVelocityPage->setObjectName(QString::fromUtf8("initialVelocityPage"));
        initialVelocityPage->setGeometry(QRect(0, 0, 171, 88));
        initialVelocitySlider = new QSlider(initialVelocityPage);
        initialVelocitySlider->setObjectName(QString::fromUtf8("initialVelocitySlider"));
        initialVelocitySlider->setGeometry(QRect(0, 0, 160, 16));
        initialVelocitySlider->setValue(10);
        initialVelocitySlider->setOrientation(Qt::Horizontal);
        initialVelocitySpinBox = new QSpinBox(initialVelocityPage);
        initialVelocitySpinBox->setObjectName(QString::fromUtf8("initialVelocitySpinBox"));
        initialVelocitySpinBox->setGeometry(QRect(10, 30, 42, 22));
        initialVelocitySpinBox->setStyleSheet(QString::fromUtf8("QSpinBox {color: green;}"));
        initialVelocitySpinBox->setValue(10);
        slidersBox->addItem(initialVelocityPage, QString::fromUtf8("Initial Velocity"));
        heightPage = new QWidget();
        heightPage->setObjectName(QString::fromUtf8("heightPage"));
        heightPage->setGeometry(QRect(0, 0, 171, 88));
        heightSlider = new QSlider(heightPage);
        heightSlider->setObjectName(QString::fromUtf8("heightSlider"));
        heightSlider->setGeometry(QRect(0, 0, 160, 16));
        heightSlider->setMaximum(150);
        heightSlider->setValue(3);
        heightSlider->setOrientation(Qt::Horizontal);
        heightSpinBox = new QSpinBox(heightPage);
        heightSpinBox->setObjectName(QString::fromUtf8("heightSpinBox"));
        heightSpinBox->setGeometry(QRect(10, 30, 42, 22));
        heightSpinBox->setValue(3);
        slidersBox->addItem(heightPage, QString::fromUtf8("Height"));
        anglePage = new QWidget();
        anglePage->setObjectName(QString::fromUtf8("anglePage"));
        anglePage->setGeometry(QRect(0, 0, 171, 88));
        angleSlider = new QSlider(anglePage);
        angleSlider->setObjectName(QString::fromUtf8("angleSlider"));
        angleSlider->setGeometry(QRect(0, 0, 160, 16));
        angleSlider->setMinimum(-90);
        angleSlider->setMaximum(90);
        angleSlider->setValue(30);
        angleSlider->setOrientation(Qt::Horizontal);
        angleSpinBox = new QSpinBox(anglePage);
        angleSpinBox->setObjectName(QString::fromUtf8("angleSpinBox"));
        angleSpinBox->setGeometry(QRect(20, 30, 42, 22));
        angleSpinBox->setMinimum(-90);
        angleSpinBox->setMaximum(90);
        angleSpinBox->setValue(30);
        slidersBox->addItem(anglePage, QString::fromUtf8("Angle:"));
        choice1Button = new QRadioButton(centralwidget);
        choice1Button->setObjectName(QString::fromUtf8("choice1Button"));
        choice1Button->setGeometry(QRect(20, 690, 611, 19));
        choice2Button = new QRadioButton(centralwidget);
        choice2Button->setObjectName(QString::fromUtf8("choice2Button"));
        choice2Button->setGeometry(QRect(20, 720, 671, 19));
        choice3Button = new QRadioButton(centralwidget);
        choice3Button->setObjectName(QString::fromUtf8("choice3Button"));
        choice3Button->setGeometry(QRect(20, 750, 611, 19));
        choice4Button = new QRadioButton(centralwidget);
        choice4Button->setObjectName(QString::fromUtf8("choice4Button"));
        choice4Button->setGeometry(QRect(20, 780, 611, 19));
        tipLabel = new QLabel(centralwidget);
        tipLabel->setObjectName(QString::fromUtf8("tipLabel"));
        tipLabel->setGeometry(QRect(680, 680, 201, 161));
        questionNumberLabel = new QLabel(centralwidget);
        questionNumberLabel->setObjectName(QString::fromUtf8("questionNumberLabel"));
        questionNumberLabel->setGeometry(QRect(20, 610, 71, 31));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(610, 570, 91, 31));
        cannonLabel = new QLabel(centralwidget);
        cannonLabel->setObjectName(QString::fromUtf8("cannonLabel"));
        cannonLabel->setGeometry(QRect(0, 0, 500, 500));
        cannonLabel->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        groundLabel = new QLabel(centralwidget);
        groundLabel->setObjectName(QString::fromUtf8("groundLabel"));
        groundLabel->setGeometry(QRect(0, 500, 1590, 30));
        groundLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0,128,0)\n"
""));
        cannonBallLabel = new QLabel(centralwidget);
        cannonBallLabel->setObjectName(QString::fromUtf8("cannonBallLabel"));
        cannonBallLabel->setGeometry(QRect(20, 300, 60, 16));
        cannonBallLabel->setStyleSheet(QString::fromUtf8("QLabel {background-color: rgba(173, 216, 230, 0%)}"));
        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(180, 690, 80, 22));
        formulaButton = new QPushButton(centralwidget);
        formulaButton->setObjectName(QString::fromUtf8("formulaButton"));
        formulaButton->setGeometry(QRect(900, 690, 81, 31));
        resetQuizButton = new QPushButton(centralwidget);
        resetQuizButton->setObjectName(QString::fromUtf8("resetQuizButton"));
        resetQuizButton->setGeometry(QRect(1010, 690, 81, 31));
        mainButton = new QPushButton(centralwidget);
        mainButton->setObjectName(QString::fromUtf8("mainButton"));
        mainButton->setGeometry(QRect(730, 570, 91, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        slidersBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        simulationImageLabel->setText(QString());
        questionLabel->setText(QCoreApplication::translate("MainWindow", "put the questions here!", nullptr));
        fireButton->setText(QCoreApplication::translate("MainWindow", "Fire", nullptr));
        slidersBox->setItemText(slidersBox->indexOf(gravityPage), QCoreApplication::translate("MainWindow", "Gravity", nullptr));
        slidersBox->setItemText(slidersBox->indexOf(initialVelocityPage), QCoreApplication::translate("MainWindow", "Initial Velocity", nullptr));
        slidersBox->setItemText(slidersBox->indexOf(heightPage), QCoreApplication::translate("MainWindow", "Height", nullptr));
        slidersBox->setItemText(slidersBox->indexOf(anglePage), QCoreApplication::translate("MainWindow", "Angle:", nullptr));
        choice1Button->setText(QCoreApplication::translate("MainWindow", "put answer 1 here", nullptr));
        choice2Button->setText(QCoreApplication::translate("MainWindow", "put answer 2 here", nullptr));
        choice3Button->setText(QCoreApplication::translate("MainWindow", "put answer 3 here ", nullptr));
        choice4Button->setText(QCoreApplication::translate("MainWindow", "put answer 4 here", nullptr));
        tipLabel->setText(QString());
        questionNumberLabel->setText(QCoreApplication::translate("MainWindow", "Question:", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        cannonLabel->setText(QString());
        groundLabel->setText(QString());
        cannonBallLabel->setText(QString());
        submitButton->setText(QCoreApplication::translate("MainWindow", "submit", nullptr));
        formulaButton->setText(QCoreApplication::translate("MainWindow", "Formula Page", nullptr));
        resetQuizButton->setText(QCoreApplication::translate("MainWindow", "Reset Quiz", nullptr));
        mainButton->setText(QCoreApplication::translate("MainWindow", "Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
