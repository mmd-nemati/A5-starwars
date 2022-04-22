#include "../src/rsdl.hpp"
#include "spaceship.hpp"

Spaceship::Spaceship()
  :  body(462, 768-SPACESHIP_HEIGHT, SPACESHIP_WIDTH, SPACESHIP_HEIGHT)
{
    location =  {462, 768-SPACESHIP_HEIGHT};
    vx = INITIAL_VELOCITY;
    vy = INITIAL_VELOCITY;
    ax = MOVING_VELOCITY;
    ay = MOVING_VELOCITY;
    is_moving = false;
    //body = Rectangle(location.x, location.y);
}

void Spaceship::set_moving(int _dir)
{
    is_moving = true;
    dir = _dir;
}

bool goes_out_of_map(int direction, int coordinate)
{
    switch (direction)
    {
        case UP:
            return coordinate < 10;
        
        case DOWN:
            return (coordinate + SPACESHIP_HEIGHT > 760);
        
        case LEFT:
            return coordinate < 23;
        
        case RIGHT:
            return (coordinate + SPACESHIP_WIDTH > 1010);
        default:;
    }

    return true;
}

void Spaceship::move()
{
    if (is_moving)
    {
        if (dir == UP && !goes_out_of_map(UP, location.y))
        {
            vy = MOVING_VELOCITY;
            location.y -= vy;
            body = Rectangle(location.x, location.y, SPACESHIP_WIDTH, SPACESHIP_HEIGHT);
        }
        else if (dir == DOWN && !goes_out_of_map(DOWN, location.y))
        {
            vy = MOVING_VELOCITY;
            location.y += vy;
            body = Rectangle(location.x, location.y, SPACESHIP_WIDTH, SPACESHIP_HEIGHT);
        }
        if (dir == LEFT && !goes_out_of_map(LEFT, location.x))
        {
            vx = MOVING_VELOCITY;
            location.x -= vx;
            body = Rectangle(location.x, location.y, SPACESHIP_WIDTH, SPACESHIP_HEIGHT);
        }
        else if (dir == RIGHT && !goes_out_of_map(RIGHT, location.x))
        {
            vx = MOVING_VELOCITY;
            location.x += vx;
            body = Rectangle(location.x, location.y, SPACESHIP_WIDTH, SPACESHIP_HEIGHT);
        }
    }
}

void Spaceship::stop()
{
    vx = 0;
    vy = 0;
    is_moving = false;
}

void Spaceship::shoot()
{
    Point weapon_location = {location.x + SPACESHIP_WIDTH/2 - BULLET_SCALE/2, location.y};
    Bullet new_bullet(weapon_location);
    new_bullet.set_location(weapon_location);
    bullets.push_back(new_bullet);
}

bool is_out_of_map(Point _loc)
{
    return (_loc.x < 0 || _loc.x > 1024 || _loc.y < 0 || _loc.y > 768);
}

void Spaceship::bullets_move()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (is_out_of_map(bullets[i].get_loc()))
        {
            bullets.erase(bullets.begin() + i);
            continue;
        }
        bullets[i].move();
    }
}