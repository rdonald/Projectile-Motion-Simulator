/*
 * Matthew Hunsaker
 * Nick
 * Albert
 *
 */


/**
 * the world state of projectile
 *
 */
#include "worldstate.h"
#include <QtDebug>

//Box2d uses meters, kilograms, and seconds

/**
 * @brief WorldState::WorldState
 *
 * set up the client with the initial values
 * also call this constructor when the user hits reset button
 */

// Default Constructor for the world state.
WorldState::WorldState() {

}

// Constructor for the world state.
WorldState::WorldState(double initialVelocity, double gravity, double angle, double height) {
    this->initialVelocity = initialVelocity;
    this->gravity = gravity;
    this->angle = angle;
    this->height = height;
}

// May not need this now that the world is no longer stored on the heap
WorldState::~WorldState()
{

}

// Set the initial velocity at which the cannon ball is fired.
void WorldState::setInitialVelocity(double initialVelocity) {
    this->initialVelocity = initialVelocity;
}

// Set the gravity of the world.
void WorldState::setGravity(double gravity) {
    this->gravity = gravity;
}

// Set the angle at which the cannon ball is fired.
void WorldState::setAngle(double angle) {
    this->angle = angle;
}

// Set the height at which the cannon ball is fired.
void WorldState::setHeight(double height) {
    this->height = height;
}

// Return the initial velocity at which the cannon ball is fired.
double WorldState::getInitialVelocity() {
    return this->initialVelocity;
}

// Return the gravity of the world.
double WorldState::getGravity() {
    return this->gravity;
}

// Return the angle at which the cannon ball is fired.
double WorldState::getAngle() {
    return this->angle;
}

// Return the height at which the cannon ball is fired.
double WorldState::getHeight() {
    return this->height;
}

// Calculate the path of the cannon ball through the world and return it as
// a vector of tuples holding the x-y values
void WorldState::calculateTrajectory(std::vector<std::tuple<float, float> > & trajectory)
{
    b2Vec2 gravtyVec(0.0f, -gravity);
    b2World world(gravtyVec);
    b2Body* body = nullptr;
    b2BodyDef worldGroundBodyDef;
    worldGroundBodyDef.position.Set(0.0f, 20.0f);
    b2Body* worldGroundBody = world.CreateBody(&worldGroundBodyDef);
    b2PolygonShape worldGroundBox;
    worldGroundBox.SetAsBox(0.0f, 0.0f);
    worldGroundBody->CreateFixture(&worldGroundBox, 0.0f);

//    // Creating the cannon ball?
    b2BodyDef cannonBallbodyDef;
    cannonBallbodyDef.type = b2_dynamicBody;
    cannonBallbodyDef.position.Set(0.0f, this->height);
    body = world.CreateBody(&cannonBallbodyDef);

    b2PolygonShape cannonBallDynamicBox;
    cannonBallDynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef ballFixtureDef;
    ballFixtureDef.shape = &cannonBallDynamicBox;
    ballFixtureDef.density = 1.0f;

    body->CreateFixture(&ballFixtureDef);

    // Set the linear velocity of the cannonball
    body->SetLinearVelocity(b2Vec2(calculateInitalXVelocity(),calculateInitalYVelocity()));
    // Add the starting position to the vector
    b2Vec2 currentPosition = body->GetPosition();
    std::tuple<float,float> current = std::make_tuple(currentPosition.x, currentPosition.y);
    // qDebug() << "X Y: " << currentPosition.x << " " << currentPosition.y;
    trajectory.push_back(current);

    emit getNextStep(trajectory, &world, body);
}

void WorldState::getNextTrajectoryStep(std::vector<std::tuple<float, float> > & trajectory, b2World* world, b2Body* body)
{
        // Iterate the world one step
        world->Step(timeStep, velIter, posIter);

        // Get the new position of the cannonball and add it to the vector
        b2Vec2 currentPosition = body->GetPosition();
        std::tuple<float,float> current = std::make_tuple(currentPosition.x, currentPosition.y);
        trajectory.push_back(current);
        if(currentPosition.y >= -120) {
            // qDebug() << "X Y: " << currentPosition.x << " " << currentPosition.y;
            emit getNextStep(trajectory,world,body);
        }
}

// Calculate the x component of the initial velocity
double WorldState::calculateInitalXVelocity()
{
    // Apply the value of the angle converted to radians to get the x value of the velocity
    return initialVelocity * cos(convertAngle());
}

// Calculate the y component of the initial velocity
double WorldState::calculateInitalYVelocity()
{
    // Apply the value of the angle converted to radians to get the y value of the velocity
    return initialVelocity * sin(convertAngle());
}

// Convert the angle from degrees to radians. May want to move
// this over to the view so we don't have to do this here
double WorldState::convertAngle()
{
    // Convert the angle to radians from degrees
    return (M_PI / 180.0) * angle;
}
