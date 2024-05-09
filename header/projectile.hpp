#pragma once
// #include "plant.hpp"
//#include "utilities.hpp"
#include "zombie.hpp"

class Projectile
{
public:
    Projectile(RenderWindow *_window_ptr, string projectile_type_png) : window_ptr(_window_ptr)
    {
        if (!projectile_texture.loadFromFile(PICS_PATH + projectile_type_png))
        {
            cerr << "cant upload image!";
        }
        projectile_sprite.setTexture(projectile_texture);
        projectile_sprite.setScale(0.018, 0.018);
    }
    Vector2i get_pos(){return pos;}
    void render();
    void update();
    string get_name() {return projectile_name;}

protected:
    int damage;
    int speed;
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
    Snow_projectile(RenderWindow *_window_ptr,Vector2i _pos, string projectile_type_png);

private:
};
