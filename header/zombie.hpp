#pragma once
#include "utilities.hpp"

class Zombie
{
public:
    Zombie(RenderWindow *_window_ptr) : window_ptr(_window_ptr)
    {
        vector<int> zombie_data = read_from_file(1, 1);
        damage = zombie_data[0];
        health = zombie_data[1];
        hit_rate = zombie_data[2];
        speed = zombie_data[3];
    }
    void render();
    virtual void update() = 0;
    int get_pos_x() { return zombie_pos.x; }

protected:
    Texture zombie_texture;
    Sprite zombie_sprite;
    RenderWindow *window_ptr;
    Vector2i zombie_pos;
    int health;
    int damage;
    int speed;
    int hit_rate;
    int row;
};

class NormalZombie : public Zombie
{
public:
    NormalZombie(RenderWindow *_window_ptr, Vector2i _pos, int _row);
    // void render();
    void update();

private:
    int walking_zombie_animation_poses[46];
    int current_animation_rect_number = 0;
    Clock animation_clock;
    Clock zombie_clock;
};

class GiantZombie : public Zombie
{
public:
    GiantZombie(RenderWindow *_window_ptr, Vector2i _pos, int _row);
    // void render();
    void update();

private:
    int walking_zombie_animation_poses[33];
    int current_animation_rect_number = 0;
    Clock animation_clock;
    Clock giant_zombie_clock;
};