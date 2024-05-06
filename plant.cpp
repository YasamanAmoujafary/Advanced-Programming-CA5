#include "plant.hpp"

void Walnut::render()
{
    if (!plant_texture.loadFromFile(PICS_PATH + pic_name))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    window_ptr->draw(plant_sprite);
}
void Walnut::adding_walnut()
{
    set_pic_name();
    render();
};