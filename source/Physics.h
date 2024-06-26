#pragma once

#include "Vector2D.h"

class Physics
{
public:
    Vector2D force;
    float mass;

    Vector2D acceleration;
    Vector2D velocity;

    Physics(float mass);
    ~Physics();

    void update(Vector2D &direction, float defaultSpeed);
    void kinematics();
    void directionInForce(Vector2D &direction, float defaultSpeed);
};