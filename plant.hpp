#include "includes.hpp"

class Plant {
public:
    Plant(RenderWindow *_window_ptr){window_ptr = _window_ptr;}
    virtual void render(RenderWindow &window) = 0;
protected:
    Texture plant_texture;
    Sprite  plant_sprite;
    int health;
    //int id;
    string pic_name;
    Vector2i position;
    int price;
    int cool_down;
    RenderWindow *window_ptr;
    //void update();
};

class Walnut : public Plant{
    public:
    void set_pic_name(){pic_name = "Walnut.png";}
    
    void render(RenderWindow &window);
    private:
};