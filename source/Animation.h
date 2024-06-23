#pragma once

#include <SDL.h>

#include "GOLoader.h"
#include "Vector2D.h"

class Animation
{
public:
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    int columnFrame;
    int rowFrame;
    int gifFrameDelay;
    int gifSteps;

    Animation(const GOLoader loader);
    ~Animation();

    void update(const bool gif, const Vector2D &position, const Vector2D &direction);
    void const draw();
    void gif();

    void face(const Vector2D &direction);
};