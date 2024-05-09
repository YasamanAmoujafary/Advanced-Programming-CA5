#include "projectile.hpp"

Projectile::Projectile(RenderWindow *_window_ptr, string projectile_type_png)
{
    window_ptr = _window_ptr;
    if (!projectile_texture.loadFromFile(PICS_PATH + projectile_type_png))
    {
        cerr << "cant upload image!";
    }
    projectile_sprite.setTexture(projectile_texture);
    projectile_sprite.setScale(1, 1);
}

void Projectile::render()
{
    window_ptr->draw(projectile_sprite);
}

void Projectile::update()
{
    pos.x += speed; // implement time;
    projectile_sprite.setPosition(pos.x, pos.y);
}

Regular_projectile::Regular_projectile(RenderWindow *_window_ptr, Vector2i _pos, string projectile_type_png)
    : Projectile(_window_ptr, projectile_type_png)
{
    pos = _pos;
    vector<int> file_data;
    file_data = read_from_file(2, 1);
    damage = file_data[0];
    speed = file_data[4];
}
Snow_projectile::Snow_projectile(RenderWindow *_window_ptr, Vector2i _pos, string projectile_type_png)
    : Projectile(_window_ptr, projectile_type_png)
{
    pos = _pos;
    vector<int> file_data;
    file_data = read_from_file(2, 2);
    damage = file_data[0];
    speed = file_data[4];
}
