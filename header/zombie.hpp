#pragma once
#include "utilities.hpp"

class Zombie
{
public:
    // virtual void render();
    // virtual void update();

protected:
    Texture zombie_texture;
    Sprite zombie_sprite;
    int health;
    int damage;
    int speed;
    int hit_rate;
};

class NormalZombie : public Zombie
{
public:
    // void render();
    // void update();
private:
};

class GiantZombie : public Zombie
{
public:
    // void render();
    // void update();
private:
};