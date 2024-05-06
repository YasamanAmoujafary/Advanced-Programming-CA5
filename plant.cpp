#include "plant.hpp"

void Plant::render()
{
    if (!plant_texture.loadFromFile(PICS_PATH + pic_name))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
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

PeaShooter::PeaShooter(RenderWindow *_window_ptr, Vector2i _pos)
          :Plant(_window_ptr)
{
    pos = _pos;
}
