#include "plant.hpp"

Walnut::Walnut(RenderWindow *_window_ptr, Vector2i _pos)
    : Plant(_window_ptr)
{
    pos = _pos;
}
void Walnut::render()
{
    if (!plant_texture.loadFromFile(PICS_PATH + "Wallnut_body.png"))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    plant_sprite.setScale(0.8,0.8);
    plant_sprite.setPosition(pos.x, pos.y);
    window_ptr->draw(plant_sprite);
}


Sunflower::Sunflower(RenderWindow *_window_ptr, Vector2i _pos)
    : Plant(_window_ptr)
{
    pos = _pos;
}

void Sunflower::render()
{
    if (!plant_texture.loadFromFile(PICS_PATH + "Sunflower.png"))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    plant_sprite.setScale(0.05,0.05);
    plant_sprite.setPosition(pos.x, pos.y);
    window_ptr->draw(plant_sprite);
}

PeaShooter::PeaShooter(RenderWindow *_window_ptr, Vector2i _pos)
    : Plant(_window_ptr)
{
    pos = _pos;
}

void PeaShooter::render()
{
    if (!plant_texture.loadFromFile(PICS_PATH + "Peashooter.png"))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    plant_sprite.setScale(0.06,0.06);
    plant_sprite.setPosition(pos.x, pos.y);
    window_ptr->draw(plant_sprite);
}

Snowpea::Snowpea(RenderWindow *_window_ptr, Vector2i _pos)
    : Plant(_window_ptr)
{
    pos = _pos;
}

void Snowpea::render()
{
    if (!plant_texture.loadFromFile(PICS_PATH + "snowpea.png"))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    plant_sprite.setScale(0.2,0.2);
    plant_sprite.setPosition(pos.x, pos.y);
    window_ptr->draw(plant_sprite);
}
