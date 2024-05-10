#pragma once
#include "utilities.hpp"

class Zombie
{
public:
    Zombie(RenderWindow *_window_ptr, string zombie_type_png) : window_ptr(_window_ptr)
    {
        if(!zombie_texture.loadFromFile(PICS_PATH + zombie_type_png))
        {
           cerr << "cant upload image!";
        }
        zombie_sprite.setTexture(zombie_texture);
        zombie_sprite.setScale(1,1);
        IntRect rect;
        rect.width = 34;
        rect.height = 62;
        zombie_sprite.setTextureRect(rect);
    }
    // virtual void render();
    // virtual void update();

protected:
    Texture zombie_texture;
    Sprite zombie_sprite;
    RenderWindow *window_ptr;
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