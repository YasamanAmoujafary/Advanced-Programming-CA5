#include "includes.hpp"

class Plant
{
public:
    Plant(RenderWindow *_window_ptr) : window_ptr(_window_ptr) {}
    virtual void render() = 0;
    Vector2i get_pos(){return pos;}
    Sprite get_plant_sprite(){return plant_sprite;}
    void change_pos(int x,int y){pos.x = x; pos.y = y;}
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
    Vector2i pos;
};

class Walnut : public Plant
{
public:
    Walnut(RenderWindow *_window_ptr, Vector2i _pos);
    // void set_pic_name() { pic_name = "Wallnut_body.png"; }
    void render();

private:
};

class Sunflower : public Plant
{
public:
    Sunflower(RenderWindow *_window_ptr, Vector2i _pos);
    void render();

private:
};

class PeaShooter : public Plant
{
public:
    PeaShooter(RenderWindow *_window_ptr, Vector2i _pos);
    void render();

private:
};

class Snowpea : public Plant
{
public:
    Snowpea(RenderWindow *_window_ptr, Vector2i _pos);
    void render();

private:
};
