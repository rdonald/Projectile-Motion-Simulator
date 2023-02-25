#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <questionhandler.h>
#include <projectileengine.h>
#include "startupmenu.h"

#include <QPixmap>
#include <QLabel>
#include <tuple>
#include <vector>

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QTimer>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, StartUpMenu *startUpMenu = nullptr);
    ~MainWindow();


signals:
    void updateGravity(int newGravityValue);
    void updateVelocity(int newInitialVelocity);
    void updateHeight(int newHeightValue);
    void updateAngle(int newAngleValue);
    void updateToDefaultWorldState();

    void sendFireCommand();
    void returnToMain();

public slots:
    void updateVariable(int varType, double value);
    void drawCannon(double platform_height, double cannon_angle);
    void show_Question(QString question);
    void show_MultipleChoice(QVector<QString> choices);

private slots:
    void show_nextQuestion();
    void on_angleSlider_valueChanged(int newAngle);
    void on_heightSlider_valueChanged(int newHeight);
    void on_initialVelocitySlider_valueChanged(int newVelocity);
    void on_gravitySlider_valueChanged(int newGravity);
    void on_angleSpinBox_valueChanged(int arg1);
    void on_heightSpinBox_valueChanged(int arg1);
    void on_initialVelocitySpinBox_valueChanged(int arg1);
    void on_gravitySpinBox_valueChanged(int arg1);
    void on_resetButton_clicked();
    void on_fireButton_clicked();

    void displayTrajectory(std::vector<std::tuple<float,float>>);

    void receiveIsTakingQuiz(bool);

    void on_choice1Button_clicked();
    void on_choice2Button_clicked();
    void on_choice3Button_clicked();
    void on_choice4Button_clicked();

    void on_submitButton_clicked();
    void on_formulaButton_clicked();
    void on_resetQuizButton_clicked();
    void on_mainButton_clicked();

private:
    Ui::MainWindow *ui;
    ProjectileEngine *engine;
    QuestionHandler *questionHandling;
    QPainter *painter;
    QPixmap *drawing_board;
    QString currentTip;
    QPainter *trajectory_painter;
    QPixmap *trajectory_board;
    QPoint *cannonOrigin;
    QPoint *lastMarkingPosition;

    int isCorrect;
    void scaleImgToFit(const double maxW, const double maxH, QImage &input);
    void drawImageCenter(QImage &img, int x, int y, int angle);
    double projectionRatio;

    void drawCannonBall(double xPhysics, double yPhysics);
    void animateProjectile(int i, const std::vector<std::tuple<float,float>> &trj);
    void drawTrajLine(int x, int y);
    void EnableOrDisableUI(bool enableOrDisable);

};
#endif // MAINWINDOW_H
