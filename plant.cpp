#include "plant.hpp"

Walnut::Walnut(RenderWindow *_window_ptr,string _plant_png_path, Vector2i _pos)
    : Plant(_window_ptr,_plant_png_path)
{
    pos = _pos;
    plant_name = "walnut";
}
void Walnut::render(int bg_pos_x, int bg_pos_y)
{
    if (!plant_texture.loadFromFile(PICS_PATH + plant_png_path))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    float scaleX = static_cast<float>(bg_pos_x) / (plant_texture.getSize().x);
    float scaleY = static_cast<float>(bg_pos_y) / (plant_texture.getSize().y);
    plant_sprite.setScale(scaleX, scaleY);
    plant_sprite.setPosition(pos.x, pos.y);
    window_ptr->draw(plant_sprite);
}

Sunflower::Sunflower(RenderWindow *_window_ptr,string _plant_png_path, Vector2i _pos)
    : Plant(_window_ptr,_plant_png_path)
{
    pos = _pos;
    plant_name = "sunflower";
}

void Sunflower::render(int bg_pos_x, int bg_pos_y)
{
    if (!plant_texture.loadFromFile(PICS_PATH + plant_png_path))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    float scaleX = static_cast<float>(bg_pos_x) / (plant_texture.getSize().x);
    float scaleY = static_cast<float>(bg_pos_y) / (plant_texture.getSize().y);
    plant_sprite.setScale(scaleX, scaleY);
    plant_sprite.setPosition(pos.x, pos.y);
    window_ptr->draw(plant_sprite);
}

PeaShooter::PeaShooter(RenderWindow *_window_ptr,string _plant_png_path,Vector2i _pos)
    : Plant(_window_ptr,_plant_png_path)
{
    pos = _pos;
    plant_name = "peashooter";
}

void PeaShooter::render(int bg_pos_x, int bg_pos_y)
{
    if (!plant_texture.loadFromFile(PICS_PATH + plant_png_path))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    float scaleX = static_cast<float>(bg_pos_x) / (plant_texture.getSize().x);
    float scaleY = static_cast<float>(bg_pos_y) / (plant_texture.getSize().y);
    plant_sprite.setScale(scaleX, scaleY);
    plant_sprite.setPosition(pos.x, pos.y);
    window_ptr->draw(plant_sprite);
}

Snowpea::Snowpea(RenderWindow *_window_ptr,string _plant_png_path, Vector2i _pos)
    : Plant(_window_ptr,_plant_png_path)
{
    pos = _pos;
    plant_name = "snowpea";
}

void Snowpea::render(int bg_pos_x, int bg_pos_y)
{
    if (!plant_texture.loadFromFile(PICS_PATH + plant_png_path))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    float scaleX = static_cast<float>(bg_pos_x) / (plant_texture.getSize().x);
    float scaleY = static_cast<float>(bg_pos_y) / (plant_texture.getSize().y);
    plant_sprite.setScale(scaleX, scaleY);
    plant_sprite.setPosition(pos.x, pos.y);
    window_ptr->draw(plant_sprite);
}

Watermelon::Watermelon(RenderWindow *_window_ptr,string _plant_png_path, Vector2i _pos)
    : Plant(_window_ptr,_plant_png_path)
{
    pos = _pos;
    plant_name = "watermelon";
}

void Watermelon::render(int bg_pos_x, int bg_pos_y)
{
    if (!plant_texture.loadFromFile(PICS_PATH + plant_png_path))
    {
        cerr << "cant upload image!";
    }
    plant_sprite.setTexture(plant_texture);
    float scaleX = static_cast<float>(bg_pos_x) / (plant_texture.getSize().x);
    float scaleY = static_cast<float>(bg_pos_y) / (plant_texture.getSize().y);
    plant_sprite.setScale(scaleX, scaleY);
    plant_sprite.setPosition(pos.x, pos.y);
    window_ptr->draw(plant_sprite);
}
