#include "includes.hpp"

class Plant
{
public:
    Plant(RenderWindow *_window_ptr) : window_ptr(_window_ptr){}
    virtual void render() = 0;

protected:
    Texture plant_texture;
    Sprite plant_sprite;
    int health;
    // int id;
    string pic_name;
    int price;
    int cool_down;
    RenderWindow *window_ptr;
    // void update();
};

class Walnut : public Plant
{
public:
    Walnut(RenderWindow *_window_ptr, Vector2i _pos);
    void set_pic_name() { pic_name = "Wallnut_body.png"; }
    virtual void rend();
private:
    Vector2i pos;
};

class Sunflower : public Plant
{
public:
    Sunflower(RenderWindow *_window_ptr, Vector2i _pos);
    virtual void rend();

private:
    Vector2i pos;

};

class PeaShooter : public Plant
{
public:
    PeaShooter(RenderWindow *_window_ptr, Vector2i _pos);
private:
    Vector2i pos;
};