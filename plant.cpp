#include "plant.hpp"

void Walnut::render()
{
    if (!plant_texture.loadFromFile(PICS_PATH + "Wallnut_body.png"))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    //plant_sprite.scale(1,1);
    window_ptr->draw(plant_sprite);
}

Walnut::Walnut(RenderWindow *_window_ptr, Vector2i _pos)
      :Plant(_window_ptr)
      {
        pos = _pos;
      }

Sunflower::Sunflower(RenderWindow *_window_ptr, Vector2i _pos)
         :Plant(_window_ptr)
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
    //plant_sprite.scale(0.1,0.15);
    window_ptr->draw(plant_sprite);
}

PeaShooter::PeaShooter(RenderWindow *_window_ptr, Vector2i _pos)
          :Plant(_window_ptr)
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
    //plant_sprite.scale(0.1,0.15);
    window_ptr->draw(plant_sprite);
}
