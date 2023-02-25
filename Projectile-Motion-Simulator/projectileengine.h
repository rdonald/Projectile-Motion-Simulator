/*
 * @authors:
 * - Matthew Hunsaker
 * - Nick
 * - Albert
 * - Rory
 */

#ifndef PROJECTILEENGINE_H
#define PROJECTILEENGINE_H

#include <QObject>
#include <worldstate.h>

class ProjectileEngine : public QObject
{
    Q_OBJECT
public:
    explicit ProjectileEngine(QObject *parent = nullptr);
    void initialEmit();
    enum PHYSICS_VAR{
        INIT_VELOCITY,
        GRAVITY,
        ANGLE,
        HEIGHT,
    };

signals:
    void updateVariable(int varType, double value);
    void updateCannon(double height, double angle);
    void getTrajectory(std::vector<std::tuple<float, float>>&);
    void sendTrajectory(std::vector<std::tuple<float, float>>);

public slots:
    void changeAngleInModel(int newAngle);
    void changeHeightInModel(int newHeight);
    void changeGravityInModel(int newGravity);
    void changeVelocityInModel(int newVelocity);
    void changeWorldStateToDefault();
    void getFire();

private:
    WorldState* worldstate;

};

#endif // PROJECTILEENGINE_H
