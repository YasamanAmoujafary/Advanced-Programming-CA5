 #include "plant.hpp"
 
void Plant::render(RenderWindow &window)
{
    if (!plant_texture.loadFromFile(PICS_PATH + pic_name))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    window.draw(plant_sprite);
}