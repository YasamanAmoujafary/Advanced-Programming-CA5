#pragma once
#include "utilities.hpp"

class Zombie
{
public:
    Zombie(RenderWindow *_window_ptr) : window_ptr(_window_ptr)
    {
        is_moving = true;
        is_in_snow_mode = false;
    }
    void render();
    virtual void update() = 0;
    int get_pos_x() { return zombie_pos.x; }
    FloatRect get_rect() { return zombie_sprite.getGlobalBounds(); }
    void update_health(int projectile_damage);
    int get_health() { return health; }
    void change_is_in_snow_mode()
    {
        cout << "we are entering snow mode" << endl;
        is_in_snow_mode = true;
        speed = zombie_data[3] / 2;
        in_snow_clock.restart();
    }
    bool get_in_snow_mode() { return is_in_snow_mode; }
    int get_row() { return row; }
    void update_texture(string zombie_png, float scale_x, float scale_y, int width, int height);
    int get_damage() { return damage; }
    bool is_in_hit_moment()
    {
        if (hit_rate_clock.getElapsedTime().asSeconds() >= hit_rate)
        {
            hit_rate_clock.restart();
            return true;
        }
        return false;
    }
    void make_stable() { is_moving = false; }
    bool get_is_moving() { return is_moving; }
    void set_in_motion() { is_moving = true; }
protected:
    Texture zombie_texture;
    Sprite zombie_sprite;
    RenderWindow *window_ptr;
    Vector2i zombie_pos;
    vector<int> zombie_data;
    int health;
    int damage;
    int speed;
    int hit_rate;
    int row;
    bool is_in_snow_mode;
    Clock in_snow_clock;
    Clock hit_rate_clock;
    bool is_moving;
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