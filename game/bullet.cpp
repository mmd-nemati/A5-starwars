#include "bullet.hpp"

Bullet::Bullet(Point _loc)
  : body(_loc.x, _loc.y, BULLET_SCALE, BULLET_SCALE)
{
    location = {_loc.x, _loc.y};
    damage = BULLET_DAMAGE;
}

void Bullet::move()
{
    vy = BULLET_SPEED;
    location.y += vy;
}

void Bullet::set_location(Point _loc)
{
    location = _loc;
}