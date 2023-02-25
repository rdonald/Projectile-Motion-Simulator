/*
 * @authors:
 * - Matthew Hunsaker
 * - Nick
 * - Albert
 * - Rory
 */

/**
 * the controller that handles the physics logic for the projectile motion
 * directly accessing the physicsObjectModel and communicate with the view if there is any changes
 *
 * how view, controller and model commmunicate with each others here.
 * mainwindow->projectileengine->worldstate->projectileengine->mainwindow
 */

//mainwindow->projectileengine->worldstate->projectileengine->mainwindow

#include "projectileengine.h"
#include <QtDebug>

const double DEFAULT_INIT_VELOCITY = 50;
const double DEFAULT_GRAVITY = 10;
const double DEFAULT_ANGLE = 30;
const double DEFAULT_HEIGHT = 80;

ProjectileEngine::ProjectileEngine(QObject *parent) : QObject(parent)
{
    this->worldstate = new WorldState(DEFAULT_INIT_VELOCITY, DEFAULT_GRAVITY, DEFAULT_ANGLE, DEFAULT_HEIGHT);

    connect(this,
            &ProjectileEngine::getTrajectory,
            this->worldstate,
            &WorldState::calculateTrajectory);
    connect(this->worldstate,
            &WorldState::getNextStep,
            this->worldstate,
            &WorldState::getNextTrajectoryStep);
}

// double initialVelocity, double gravity, double angle, double height
void ProjectileEngine::initialEmit() {
    emit updateVariable(ProjectileEngine::ANGLE, worldstate->getAngle());
    emit updateVariable(ProjectileEngine::HEIGHT, worldstate->getHeight());
    emit updateVariable(ProjectileEngine::INIT_VELOCITY, worldstate->getInitialVelocity());
    emit updateVariable(ProjectileEngine::GRAVITY, worldstate->getGravity());
    emit updateCannon(this->worldstate->getHeight(), this->worldstate->getAngle());
}

void ProjectileEngine::changeAngleInModel(int newAngle) {
    this->worldstate->setAngle(newAngle);
    emit updateVariable(ProjectileEngine::ANGLE, newAngle);
    emit updateCannon(this->worldstate->getHeight(), this->worldstate->getAngle());
}

void ProjectileEngine::changeHeightInModel(int newHeight) {
    this->worldstate->setHeight(newHeight);
    emit updateVariable(ProjectileEngine::HEIGHT, newHeight);
    emit updateCannon(this->worldstate->getHeight(), this->worldstate->getAngle());
}

void ProjectileEngine::changeVelocityInModel(int newVelocity) {
    this->worldstate->setInitialVelocity(newVelocity);
    emit updateVariable(ProjectileEngine::INIT_VELOCITY, newVelocity);
}

void ProjectileEngine::changeGravityInModel(int newGravity) {
    this->worldstate->setGravity(newGravity);
    emit updateVariable(ProjectileEngine::GRAVITY, newGravity);
}

void ProjectileEngine::changeWorldStateToDefault() {
    this->worldstate->setAngle(DEFAULT_ANGLE);
    this->worldstate->setHeight(DEFAULT_HEIGHT);
    this->worldstate->setGravity(DEFAULT_GRAVITY);
    this->worldstate->setInitialVelocity(DEFAULT_INIT_VELOCITY);

    emit updateVariable(ProjectileEngine::ANGLE, DEFAULT_ANGLE);
    emit updateVariable(ProjectileEngine::HEIGHT, DEFAULT_HEIGHT);
    emit updateVariable(ProjectileEngine::GRAVITY, DEFAULT_GRAVITY);
    emit updateVariable(ProjectileEngine::INIT_VELOCITY, DEFAULT_INIT_VELOCITY);
}

void ProjectileEngine::getFire() {

    std::vector<std::tuple<float, float>> trj;
    emit getTrajectory(trj);
    //emit name of signal for fire
    emit sendTrajectory(trj);
}
