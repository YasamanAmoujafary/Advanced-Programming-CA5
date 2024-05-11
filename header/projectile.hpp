#pragma once
#include "zombie.hpp"

class Projectile
{
public:
    Projectile(RenderWindow *_window_ptr, string projectile_type_png);
    void render();
    void update();
    Vector2i get_pos() { return pos; }
    string get_name() { return projectile_name; }
    FloatRect get_rect() { return projectile_sprite.getGlobalBounds(); }
    int get_damage() { return damage; }
    string get_projectile_name() { return projectile_name; }

protected:
    int damage;
    int speed;
    vector<int> file_data;
    string projectile_name;
    RenderWindow *window_ptr;
    Texture projectile_texture;
    Sprite projectile_sprite;
    Vector2i pos;
    Clock projectile_clock;
};

class Regular_projectile : public Projectile
{
public:
    Regular_projectile(RenderWindow *_window_ptr, Vector2i _pos, string projectile_type_png);

private:
};

class Snow_projectile : public Projectile
{
public:
    Snow_projectile(RenderWindow *_window_ptr, Vector2i _pos, string projectile_type_png);

private:
};
