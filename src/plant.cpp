#include "plant.hpp"

Walnut::Walnut(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos)
    : Plant(_window_ptr, _plant_png_path, _pos)
{
    plant_name = "walnut";
    vector<int> file_data;
    file_data = read_from_file(2, 5);
    health = file_data[1];
    cooldown = file_data[2];
    hit_rate = file_data[3];
    price = file_data[5];
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

Sunflower::Sunflower(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos)
    : Plant(_window_ptr, _plant_png_path, _pos)
{
    plant_name = "sunflower";
    vector<int> file_data;
    file_data = read_from_file(2, 4);
    health = file_data[1];
    cooldown = file_data[2];
    hit_rate = file_data[3];
    price = file_data[5];
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

PeaShooter::PeaShooter(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos)
    : Plant(_window_ptr, _plant_png_path, _pos)
{
    plant_name = "peashooter";
    vector<int> file_data;
    file_data = read_from_file(2, 1);
    health = file_data[1];
    cooldown = file_data[2];
    hit_rate = file_data[3];
    price = file_data[5];
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

SnowPeaShooter::SnowPeaShooter(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos)
    : Plant(_window_ptr, _plant_png_path, _pos)
{
    plant_name = "snowpeashooter";
    vector<int> file_data;
    file_data = read_from_file(2, 2);
    health = file_data[1];
    cooldown = file_data[2];
    hit_rate = file_data[3];
    price = file_data[5];
}

void SnowPeaShooter::render(int bg_pos_x, int bg_pos_y)
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

Watermelon::Watermelon(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos)
    : Plant(_window_ptr, _plant_png_path, _pos)
{
    plant_name = "watermelon";
    vector<int> file_data;
    file_data = read_from_file(2, 3);
    health = file_data[1];
    cooldown = file_data[2];
    hit_rate = file_data[3];
    price = file_data[5];
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

void PeaShooter::update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row)
{
    plantElapsed = plantClock.getElapsedTime();
    if (plantElapsed.asSeconds() >= hit_rate)
    {
        plantClock.restart();
        Vector2i projectile_pos;
        projectile_pos.y = pos.y + 20;
        projectile_pos.x = pos.x + 60;

        if (num_zombies_in_row[row - 1] != 0)
        {
            Regular_projectile *regular_projectile = new Regular_projectile(window_ptr, projectile_pos, REGULAR_PROJECTILE_PNG);
            projectiles.push_back(regular_projectile);
        }
    }
}

void SnowPeaShooter::update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row)
{
    plantElapsed = plantClock.getElapsedTime();
    if (plantElapsed.asSeconds() >= hit_rate)
    {
        plantClock.restart();
        Vector2i projectile_pos;
        projectile_pos.y = pos.y + 20;
        projectile_pos.x = pos.x + 60;
        if (num_zombies_in_row[row - 1] != 0)
        {
            Snow_projectile *snow_projectile = new Snow_projectile(window_ptr, projectile_pos, SNOW_PROJECTILE_PNG);
            projectiles.push_back(snow_projectile);
        }
    }
}
void Walnut::update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row)
{
}
void Sunflower::update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row)
{
}
void Watermelon::update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row)
{
}