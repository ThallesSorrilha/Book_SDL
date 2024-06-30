#pragma once

#include "GOLoader.h"
#include "Vector2D.h"

class Dimension
{
public:
    Vector2D position;
    Vector2D size;

    void update(Vector2D velocity);
    Vector2D calculateInvasion(const Dimension &box2);
    
    void teleportAbsolute(const float x, const float y);
    void teleportRelative(const float x, const float y);
    void teleportAbsolute(const Vector2D newPosition);
    void teleportRelative(const Vector2D newPosition);

    Dimension(const GOLoader loader);
    ~Dimension();
};