#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <math.h>

MainWindow::MainWindow(QWidget *parent, StartUpMenu *startUpMenu)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->ui->tipLabel->setWordWrap(true);

    double bw = this->ui->cannonLabel->width();
    double bh = this->ui->cannonLabel->height();
    this->drawing_board = new QPixmap(bw, bh); // create a temp pixmap for painter to draw on
    drawing_board->fill(QColor(0, 0, 0, 0));
    this->painter = new QPainter(drawing_board);

    double simulatorW = this->ui->simulationImageLabel->width();
    double simulatorH = this->ui->simulationImageLabel->height();
    this->trajectory_board = new QPixmap(simulatorW, simulatorH);
    trajectory_board->fill(QColor(173, 216, 230, 255));
    this->trajectory_painter = new QPainter(this->trajectory_board);

    this->cannonOrigin = new QPoint();
    this->lastMarkingPosition = new QPoint();

    this->engine = new ProjectileEngine();
    this->questionHandling = new QuestionHandler();

    /// team1 connects
    // Connections for Height, Angle, Velocity, and Gravity Adjustments
    connect(this,
            &MainWindow::updateAngle,
            this->engine,
            &ProjectileEngine::changeAngleInModel
            );
    connect(this,
            &MainWindow::updateHeight,
            this->engine,
            &ProjectileEngine::changeHeightInModel
            );
    connect(this,
            &MainWindow::updateGravity,
            this->engine,
            &ProjectileEngine::changeGravityInModel
            );
    connect(this,
            &MainWindow::updateVelocity,
            this->engine,
            &ProjectileEngine::changeVelocityInModel
            );
    // Connection for Reset To Default World State
    connect(this,
            &MainWindow::updateToDefaultWorldState,
            this->engine,
            &ProjectileEngine::changeWorldStateToDefault
            );
    connect(this->engine,
            &ProjectileEngine::updateCannon,
            this,
            &MainWindow::drawCannon
            );
    connect(this->engine,
            &ProjectileEngine::updateVariable,
            this,
            &MainWindow::updateVariable);

    /// team3 connects
    connect(this,
            &MainWindow::sendFireCommand,
            this->engine,
            &ProjectileEngine::getFire);

        connect(this->engine,
                &ProjectileEngine::sendTrajectory,
                this,
                &MainWindow::displayTrajectory);

        /// team2 connects
        // Controller signal to view slot controller
        connect(this->questionHandling,
                &QuestionHandler::showQuestionSignal,
                this,
                &MainWindow::show_Question);

        connect(this->questionHandling,
                &QuestionHandler::showMultipleChoiceSignal,
                this,
                &MainWindow::show_MultipleChoice);

        // sending signals to setup the initial
        this->engine->initialEmit();
        // show initial question and mutiple choice options
        this->questionHandling->showInitialQuestion();
        this->questionHandling->showInitialMultipleChoice();

    // Start up menu connects
    connect(startUpMenu,
            &StartUpMenu::sendIsTakingQuiz,
            this,
            &MainWindow::receiveIsTakingQuiz);
    connect(this,
            &MainWindow::returnToMain,
            startUpMenu,
            &StartUpMenu::returnToMain);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::scaleImgToFit
 *  scale the image to fit the label
 * @param label
 * @param input
 */
void MainWindow::scaleImgToFit(const double maxW, const double maxH, QImage &input) {
    double imageW = input.width();
    double imageH = input.height();
    bool wLonger = imageW > imageH ? true : false; // is width the longer side
    double ratio = 1;
    if (wLonger) {
        ratio = maxW/imageW;
    }
    else {
        ratio = maxH/imageH;
    }
    if (ratio > 1) {
        ratio = 1;
    }
    double imageW_to_fit = imageW * ratio;
    double imageH_to_fit = imageH * ratio;
    input = input.scaled(imageW_to_fit, imageH_to_fit);
    /*
    qDebug() << "ratio: " << ratio;
    qDebug() << "WIDTH: " << imageW_to_fit;
    qDebug() << "Height: " << imageH_to_fit;
    */
}

/**
 * @brief MainWindow::drawImageCenter
 *  draw image to center around x and y position on the painter
 * @param img
 * @param x
 * @param y
 * @param angle
 */
void MainWindow::drawImageCenter(QImage &img, int x, int y, int angle) {

    double image_width = img.width();
    double image_height = img.height();

    this->painter->save();
    // painter translation
    this->painter->translate(x, y);
    this->painter->rotate(-angle);
    this->painter->translate(-x, -y); // translate back
    this->painter->drawImage(x - image_width/2, y - image_height/2, img);
    this->painter->restore();
}

void MainWindow::drawTrajLine(int x, int y) {

    this->trajectory_painter->save();
    // draw marking dots
    this->trajectory_painter->drawEllipse(QPoint(x, y), 5, 5);

    // draw lines
    this->trajectory_painter->drawLine(x, y, this->lastMarkingPosition->x(), this->lastMarkingPosition->y());
    this->lastMarkingPosition->setX(x);
    this->lastMarkingPosition->setY(y);
    this->ui->simulationImageLabel->setPixmap(*(this->trajectory_board));
    this->trajectory_painter->restore();
}

/**
 * Sets some UI elements to a different state in
 * order to make room for the next question.
 *
 * @brief MainWindow::show_nextQuestion
 */
void MainWindow::show_nextQuestion()
{
    questionHandling->incrementQuestionNumber();

    // if its the last question then no need to continue
    // currently there are only 10 questions.
    // change the number to the amount of current questions.
    if(questionHandling->getQuestionNumber() == 10){
        return;
    }

    QString question = questionHandling->getQuestion()->question;

    this->ui->questionLabel->setText(question);

    // enable buttons
    this->ui->choice1Button->setDisabled(false);
    this->ui->choice2Button->setDisabled(false);
    this->ui->choice3Button->setDisabled(false);
    this->ui->choice4Button->setDisabled(false);

    // set the choice buttons
    this->ui->choice1Button->setText(questionHandling->getQuestion()->multipleChoiceAnswers.at(0));
    this->ui->choice2Button->setText(questionHandling->getQuestion()->multipleChoiceAnswers.at(1));
    this->ui->choice3Button->setText(questionHandling->getQuestion()->multipleChoiceAnswers.at(2));
    this->ui->choice4Button->setText(questionHandling->getQuestion()->multipleChoiceAnswers.at(3));

    // uncheck button
    this->ui->choice1Button->setAutoExclusive(false);
    this->ui->choice1Button->setChecked(false);
    this->ui->choice1Button->setAutoExclusive(true);

    this->ui->choice2Button->setAutoExclusive(false);
    this->ui->choice2Button->setChecked(false);
    this->ui->choice2Button->setAutoExclusive(true);

    this->ui->choice3Button->setAutoExclusive(false);
    this->ui->choice3Button->setChecked(false);
    this->ui->choice3Button->setAutoExclusive(true);

    this->ui->choice4Button->setAutoExclusive(false);
    this->ui->choice4Button->setChecked(false);
    this->ui->choice4Button->setAutoExclusive(true);

    // set the question number label to the next question number
    QString nextNum = "Question: " + QString::number(questionHandling->getQuestionNumber() + 1);

    this->ui->questionNumberLabel->setText(nextNum);

    // clear the tip label
    this->ui->tipLabel->setText("");
}

void MainWindow::drawCannonBall(double xPhysics, double yPhysics) {
    const QString currentDirectory = QDir::currentPath() + "/../art/";
    QImage img_cannonBall = QImage(currentDirectory + "Cannon_ball.png");

    const double labelW = ui->cannonBallLabel->width();
    const double labelH = ui->cannonBallLabel->height();

    scaleImgToFit(labelW, labelH, img_cannonBall);
    QPixmap map = QPixmap::fromImage(img_cannonBall);

    ui->cannonBallLabel->setPixmap(map);
    ui->cannonBallLabel->setGeometry(xPhysics, yPhysics, labelW, labelH);
}

/// slots

/**
 * @brief MainWindow::displayTrajectory
 * @param trj
 */
void MainWindow::displayTrajectory(std::vector<std::tuple<float,float>> trj) {

    QTimer timer;
    timer.start();

    animateProjectile(0, trj);
    timer.stop();
}

void MainWindow::animateProjectile(int i, const std::vector<std::tuple<float,float>> &trj) {

    int fps = 60;
    double deltaTime = 1000.0/fps;

    if (i < trj.size()) {
        float x = std::get<0>(trj.at(i));
        float y = std::get<1>(trj.at(i));

        double xPhysics = cannonOrigin->x() + 2 * x;
        double yPhysics = cannonOrigin->y() + projectionRatio * (ui->heightSlider->value() - y);

        if (this->lastMarkingPosition->x() == 0 && this->lastMarkingPosition->y() == 0) {
            this->lastMarkingPosition->setX(xPhysics);
            this->lastMarkingPosition->setY(yPhysics);
        }

        if (yPhysics >= 500) {
            drawTrajLine(xPhysics, 500); // draw dots correspondingly
            this->lastMarkingPosition->setX(0);
            this->lastMarkingPosition->setY(0);

            // Renable UI when projectile has hit ground
            EnableOrDisableUI(false);
            return;
        }

        if (i % 20 == 0) {
            drawTrajLine(xPhysics, yPhysics); // draw dots correspondingly
        }

        drawCannonBall(xPhysics, yPhysics);
    }
    else {
        this->lastMarkingPosition->setX(0);
        this->lastMarkingPosition->setY(0);
        return;
    }

    i++;
    QTimer::singleShot(deltaTime, this, [this, i, trj] () { this->animateProjectile(i, trj); });
}

/// slots
/**
 * draws the cannon at the platform height and cannon angle
 *
 * @brief MainWindow::drawCannon
 * @param platform_height
 * @param cannon_angle
 */
void MainWindow::drawCannon(double platform_height, double cannon_angle) {

    const QString currentDirectory = QDir::currentPath() + "/../art/";

    QImage img_cannon = QImage(currentDirectory + "cannon.png");
    QImage img_platform = QImage(currentDirectory + "platform.png");
    QImage img_stand = QImage(currentDirectory + "cannon_stand.png");
    const double board_w = ui->cannonLabel->width();
    const double board_h = ui->cannonLabel->height();

    scaleImgToFit(board_w, 0.66 * board_h, img_platform);
    scaleImgToFit(board_w, 1.0/6 * board_h, img_stand);
    scaleImgToFit(board_w / 2, 0.1 * board_h, img_cannon);

    // compute the platform x & y
    const double maxHeight = this->ui->heightSpinBox->maximum();
    const double ratio = platform_height/maxHeight;
    double platform_actual_height = img_platform.height() * ratio;
    double offsetHeightRatio = 0.1;
    img_platform = img_platform.scaled(img_platform.width(), platform_actual_height *(1+offsetHeightRatio));
    const double platform_x = board_w/2;
    const double platform_y = board_h-platform_actual_height/2 + platform_actual_height*offsetHeightRatio/2;
    // compute the stand x & y
    const double stand_x = board_w/2;
    const double stand_y = board_h - platform_actual_height - img_stand.height()/2 + 0.1 * platform_actual_height;
    // compute the cannon x & y
    const double cannon_x = stand_x;
    const double cannon_y = stand_y;

    // setting global variables
    this->projectionRatio = platform_height == 0 ? this->projectionRatio : platform_actual_height / platform_height;
    this->cannonOrigin->setX(cannon_x);
    this->cannonOrigin->setY(cannon_y);

    // actual drawing
    // clear the rect and fill the rect with a blank color
    painter->setCompositionMode (QPainter::CompositionMode_Source);
    painter->fillRect(0, 0, board_w, board_h, QBrush(QColor(0, 0, 0, 0)));
    painter->setCompositionMode (QPainter::CompositionMode_SourceOver); // this removed

    drawImageCenter(img_platform, platform_x, platform_y, 0);
    drawImageCenter(img_cannon, cannon_x, cannon_y, cannon_angle);
    drawImageCenter(img_stand, stand_x, stand_y, 0);

    //Draw Cross
    painter->drawLine(cannon_x - 60, cannon_y,cannon_x + 60, cannon_y);
    painter->drawLine(cannon_x, cannon_y - 60,cannon_x, cannon_y + 60);

    //Draw 90 degree angle box
    painter->drawLine(cannon_x, cannon_y - 10,cannon_x + 10, cannon_y - 10);
    painter->drawLine(cannon_x + 10, cannon_y - 10, cannon_x + 10, cannon_y);

    ui->cannonLabel->setPixmap(*drawing_board);
}

// shows a question
void MainWindow::show_Question(QString question)
{
    this->ui->questionLabel->setText(question);
    this->ui->questionNumberLabel->setText("Question: 1");
}

void MainWindow::show_MultipleChoice(QVector<QString> choices)
{
    // choices has to be a vector

    // now display each multiple choice on the ui
    this->ui->choice1Button->setText(choices.at(0));
    this->ui->choice2Button->setText(choices.at(1));
    this->ui->choice3Button->setText(choices.at(2));
    this->ui->choice4Button->setText(choices.at(3));
}

/**
 * @brief MainWindow::updateVariable
 *
 * @param varType
 * @param value
 */
void MainWindow::updateVariable(int varType, double value) {
    switch(varType) {
    case ProjectileEngine::ANGLE:
        if (this->ui->angleSlider->value() != value) {
            this->ui->angleSlider->setValue(value);
        }
        else {
            this->ui->angleSpinBox->setValue(value);
        }
        break;
    case ProjectileEngine::HEIGHT:
        if (this->ui->heightSlider->value() != value) {
            this->ui->heightSlider->setValue(value);
        }
        else {
            this->ui->heightSpinBox->setValue(value);
        }
        break;
    case ProjectileEngine::INIT_VELOCITY:
        if (this->ui->initialVelocitySlider->value() != value) {
            this->ui->initialVelocitySlider->setValue(value);
        }
        else {
            this->ui->initialVelocitySpinBox->setValue(value);
        }
        break;
    case ProjectileEngine::GRAVITY:
        if (this->ui->gravitySlider->value() != value) {
            this->ui->gravitySlider->setValue(value);
        } else {
            this->ui->gravitySpinBox->setValue(value);
        }
        break;
    default:
        break;
    }
}

/***
 * SLOTS for handling variable slider and spinbox value changes
 */
void MainWindow::on_angleSlider_valueChanged(int newAngle) {
    emit updateAngle(newAngle);
}

void MainWindow::on_heightSlider_valueChanged(int newHeight)
{
    emit updateHeight(newHeight);
}

void MainWindow::on_initialVelocitySlider_valueChanged(int newVelocity)
{
    emit updateVelocity(newVelocity);
}

void MainWindow::on_gravitySlider_valueChanged(int newGravity)
{
    emit updateGravity(newGravity);
}

void MainWindow::on_heightSpinBox_valueChanged(int newHeight)
{
    emit updateHeight(newHeight);
}

void MainWindow::on_angleSpinBox_valueChanged(int newAngle)
{
    emit updateAngle(newAngle);
}

void MainWindow::on_initialVelocitySpinBox_valueChanged(int newVelocity)
{
    emit updateVelocity(newVelocity);
}

void MainWindow::on_gravitySpinBox_valueChanged(int newGravity)
{
    emit updateGravity(newGravity);
}


void MainWindow::on_resetButton_clicked()
{
    this->trajectory_painter->save();

    //Erase the dots and lines from the trajectory drawing
    trajectory_painter->eraseRect(0,0, this->ui->simulationImageLabel->width(), this->ui->simulationImageLabel->height());
    trajectory_board->fill(QColor(173, 216, 230, 255));

    this->ui->simulationImageLabel->setPixmap(*(this->trajectory_board));
    this->trajectory_painter->restore();

    // Hide the cannon once it hits the ground
    this->ui->cannonBallLabel->hide();

    emit updateToDefaultWorldState();
}

void MainWindow::on_fireButton_clicked()
{
    // Disable UI and show cannon label on fire
    this->ui->cannonBallLabel->show();
    EnableOrDisableUI(true);

    emit sendFireCommand();
}

/***
 * SIGNALS for handling choice clicks
 */
void MainWindow::on_choice1Button_clicked()
{
    // need to get the tips
    QString tip = questionHandling->getTip(0);
    this->currentTip = tip;

    // if the choice text is the same string as the answer
    int areEqual = QString::compare(this->ui->choice1Button->text(), questionHandling->getAnswer(), Qt::CaseInsensitive);  // if strings are equal x should return 0
    this->isCorrect = areEqual;

}


void MainWindow::on_choice2Button_clicked()
{
    // need to get the tip
    QString tip = questionHandling->getTip(1);
    this->currentTip = tip;

    // if the choice text is the same string as the answer
    int areEqual = QString::compare(this->ui->choice2Button->text(), questionHandling->getAnswer(), Qt::CaseInsensitive);  // if strings are equal x should return 0
    this->isCorrect = areEqual;
}


void MainWindow::on_choice3Button_clicked()
{
    QString tip = questionHandling->getTip(2);
    this->currentTip = tip;

    // if the choice text is the same string as the answer
    int areEqual = QString::compare(this->ui->choice3Button->text(), questionHandling->getAnswer(), Qt::CaseInsensitive);  // if strings are equal x should return 0
    this->isCorrect = areEqual;

}


void MainWindow::on_choice4Button_clicked()
{
    // need to get the tip
    QString tip = questionHandling->getTip(3);
    this->currentTip = tip;

    // if the choice text is the same string as the answer
    int areEqual = QString::compare(this->ui->choice4Button->text(), questionHandling->getAnswer(), Qt::CaseInsensitive);  // if strings are equal x should return 0
    this->isCorrect = areEqual;
}


void MainWindow::on_submitButton_clicked()
{
    // the tips and congratulations are in the same vector.
    this->ui->tipLabel->setText(currentTip);

    if(isCorrect == 0) // its correct
    {
        // disable buttons
        this->ui->choice1Button->setDisabled(true);
        this->ui->choice2Button->setDisabled(true);
        this->ui->choice3Button->setDisabled(true);
        this->ui->choice4Button->setDisabled(true);

        QTimer::singleShot(2000, this, SLOT(show_nextQuestion()));
    }

}

void MainWindow::on_formulaButton_clicked()
{
    this->ui->formulaButton->setDisabled(true);
    QMessageBox Msgbox;
    Msgbox.setWindowModality(Qt::WindowModal);
    Msgbox.setWindowTitle("Projectile Formulas.");
    Msgbox.setText("Formulas:\n\nv_0_x = v_0 * cos(Θ) \nv_0_y = v_0 * sin(Θ) \nv_x = v_0_x \nx = x_0 + v_0_x * t \nv_y = v_0_y - g * t \ny = y_0 + v_0_y * t - (1/2) * g * t^2 \nt = [v_0_y + √(v_0_y² + 2 * g * y_0)] / g\n\nVariables:\n\nv_0 = initial velocity \nv_0_x = x component of initial velocity \nv_0_y = y component of initial velocity \nΘ = angle of launch \nx_0 = initial x position \ny_0 = initial y position(initial height) \nx = x position \ny = y position \nt = time \ng = gravity \n \n \n Formulas found in: \n \"Physics, Volume 1\" by Paul A. Tipler Copyright 1976 Worth Publishers, Inc.");
    Msgbox.exec();

    this->ui->formulaButton->setEnabled(true);
}

void MainWindow::EnableOrDisableUI(bool enableOrDisable) {
    // Disable Sliders
    this->ui->angleSlider->setDisabled(enableOrDisable);
    this->ui->initialVelocitySlider->setDisabled(enableOrDisable);
    this->ui->heightSlider->setDisabled(enableOrDisable);
    this->ui->gravitySlider->setDisabled(enableOrDisable);

    // Disable Spinboxes
    this->ui->angleSpinBox->setDisabled(enableOrDisable);
    this->ui->initialVelocitySpinBox->setDisabled(enableOrDisable);
    this->ui->heightSpinBox->setDisabled(enableOrDisable);
    this->ui->gravitySpinBox->setDisabled(enableOrDisable);

    // Disable Firing
    this->ui->fireButton->setDisabled(enableOrDisable);

    // Disable Reset
    this->ui->resetButton->setDisabled(enableOrDisable);
}


void MainWindow::receiveIsTakingQuiz(bool isQuiz)
{
    ui->choice1Button->setEnabled(isQuiz);
    ui->choice2Button->setEnabled(isQuiz);
    ui->choice3Button->setEnabled(isQuiz);
    ui->choice4Button->setEnabled(isQuiz);
    ui->questionLabel->setEnabled(isQuiz);
    ui->questionNumberLabel->setEnabled(isQuiz);
    ui->submitButton->setEnabled(isQuiz);
    ui->tipLabel->setEnabled(isQuiz);
    ui->resetQuizButton->setEnabled(isQuiz);
    ui->choice1Button->setVisible(isQuiz);
    ui->choice2Button->setVisible(isQuiz);
    ui->choice3Button->setVisible(isQuiz);
    ui->choice4Button->setVisible(isQuiz);
    ui->questionLabel->setVisible(isQuiz);
    ui->questionNumberLabel->setVisible(isQuiz);
    ui->submitButton->setVisible(isQuiz);
    ui->tipLabel->setVisible(isQuiz);
    ui->resetQuizButton->setVisible(isQuiz);
    if(!isQuiz) {
        ui->formulaButton->move(900,570);
        this->resize(1600,650);
        this->setMaximumHeight(650);
    }
    else {
        ui->formulaButton->move(900,690);
        this->setMaximumHeight(900);
        this->resize(1600,900);
    }
    this->setMaximumWidth(1582);
}

void MainWindow::on_resetQuizButton_clicked()
{
    this->questionHandling->resetQuestionNumber();
    this->questionHandling->showInitialQuestion();
    this->questionHandling->showInitialMultipleChoice();
}


void MainWindow::on_mainButton_clicked()
{
    emit returnToMain();
}

