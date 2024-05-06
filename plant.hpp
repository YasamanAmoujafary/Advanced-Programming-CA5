#include "includes.hpp"

class Plant
{
public:
    Plant(RenderWindow *_window_ptr, Vector2i _position) : window_ptr(_window_ptr), position(_position) {}
    virtual void render() = 0;

protected:
    Texture plant_texture;
    Sprite plant_sprite;
    int health;
    // int id;
    string pic_name;
    Vector2i position;
    int price;
    int cool_down;
    RenderWindow *window_ptr;
    // void update();
};

class Walnut : public Plant
{
public:
    Walnut(RenderWindow *_window, Vector2i _position) : Plant(_window, _position) {}
    void set_pic_name() { pic_name = "Wallnut_body.png"; }
    virtual void render();
    void adding_walnut();
private:
};