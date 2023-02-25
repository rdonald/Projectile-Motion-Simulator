/*
 * Matthew Hunsaker
 * Nick
 * Albert
 *
 */

#ifndef WORLDSTATE_H
#define WORLDSTATE_H

#include <QObject>
#include <box2d.h>
#include <b2_world.h>
#include <tuple>
#include <vector>
#include <math.h>

class WorldState : public QObject
{
    Q_OBJECT
public:
    WorldState();
    WorldState(double initialVelocity, double gravity, double angle, double height);
    ~WorldState();
    void setInitialVelocity(double initialVelocity);
    void setGravity(double gravity);
    void setAngle(double angle);
    void setHeight(double height);
    double getInitialVelocity();
    double getGravity();
    double getAngle();
    double getHeight();

signals:
    void getNextStep(std::vector<std::tuple<float,float>>&,b2World*, b2Body*);

    public slots:
        void calculateTrajectory(std::vector<std::tuple<float,float>>&);
        void getNextTrajectoryStep(std::vector<std::tuple<float,float>>&, b2World*, b2Body*);

private:
    double initialVelocity;
    double gravity;
    double angle;
    double height;
    // CHANGE TIME_STEP because we are not doing 60Hz for games.
    double timeStep = 1.0 / 60.0; //box2D docs recommend this value to match 60Hz for games

    //these are the velocity and position iterations that Box2d
    //uses to accurately calculate the change in values for the
    //object
    int velIter = 8;
    int posIter = 3;

    double calculateInitalXVelocity();
    double calculateInitalYVelocity();
    double convertAngle();

};

#endif // WORLDSTATE_H
