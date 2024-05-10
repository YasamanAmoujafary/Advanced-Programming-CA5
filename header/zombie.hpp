#pragma once
#include "utilities.hpp"

class Zombie
{
public:
    Zombie(RenderWindow *_window_ptr) : window_ptr(_window_ptr){

    }
    void render();
    virtual void update() = 0;

protected:
    Texture zombie_texture;
    Sprite zombie_sprite;
    RenderWindow *window_ptr;
    Vector2i zombie_pos;
    int health;
    int damage;
    int speed;
    int hit_rate;
};

class NormalZombie : public Zombie
{
public:
    NormalZombie(RenderWindow *_window_ptr, Vector2i _pos);
    // void render();
    void update();
private:
    int walking_zombie_animation_poses[46];
    int current_animation_rect_number =0;
    Clock animation_clock;
};

class GiantZombie : public Zombie
{
public:
    // void render();
    // void update();
private:
};