#include "movingenemy.hpp"

MovingEnemy::MovingEnemy(Point _loc)
 : Enemy(_loc)
{
    vx = INITIAL_MOVING_ENEMY_X_SPEED;
}

bool MovingEnemy::goes_out()
{
    if (body.x < 0 || body.x > 950)
        return true;
    return false;
}

void MovingEnemy::move()
{
    if (this->goes_out())
        vx = -vx;
    location.x += vx;
    body.x = location.x;
    body.y = location.y;
    return;
}