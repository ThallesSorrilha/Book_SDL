#include "Player.h"
#include "Definitions.h"

Player::Player(const GOLoader loader, int controlMap[4]) : GameObject(loader), control(controlMap)
{
    animation.gifFrameDelay = 200;
    type = 0;
}

void Player::handleInput()
{
    control.handleInput();

    direction = 0;

    if (control.right)
    {
        direction.x += 1;
    }
    if (control.left)
    {
        direction.x -= 1;
    }
    if (control.up)
    {
        direction.y += 1;
    }
    if (control.down)
    {
        direction.y -= 1;
    }
}

void Player::update()
{
    Player::handleInput();
    physics.update(direction, 2);

    GameObject::update();

    bool moving = this->isDirect();
    if (!moving)
    {
        animation.columnFrame = 0;
    }

    animation.update(moving, dimension.position, direction);
    animation.face(direction);
}

void Player::draw() const
{
    GameObject::draw();
}

void Player::collisionResolution(GameObject *other)
{

    if (other->type == 1)
    {
        Vector2D v = dimension.calculateInvasion(other->dimension);
        dimension.teleportRelative(dimension.calculateInvasion(other->dimension));
    }
}