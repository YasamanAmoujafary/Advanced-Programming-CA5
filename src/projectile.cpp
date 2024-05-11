#include "projectile.hpp"

Projectile::Projectile(RenderWindow *_window_ptr, string projectile_type_png) : window_ptr(_window_ptr)
{
    if (!projectile_texture.loadFromFile(PICS_PATH + projectile_type_png))
    {
        cerr << "cant upload image!";
    }
    projectile_sprite.setTexture(projectile_texture);
    projectile_sprite.setScale(0.013, 0.013);
}

void Projectile::render()
{
    window_ptr->draw(projectile_sprite);
}

void Projectile::update()
{
    if (projectile_clock.getElapsedTime().asMilliseconds() > 20)
    {
        projectile_clock.restart();
        pos.x += speed;
        projectile_sprite.setPosition(pos.x, pos.y);
    }
}

Regular_projectile::Regular_projectile(RenderWindow *_window_ptr, Vector2i _pos, string projectile_type_png)
    : Projectile(_window_ptr, projectile_type_png)
{
    projectile_name = REGULAR_PROJECTILE_NAME;
    pos = _pos;
    projectile_sprite.setPosition(_pos.x, _pos.y);
    file_data = read_from_file(2, 1);
    damage = file_data[0];
    speed = file_data[4];
}

Snow_projectile::Snow_projectile(RenderWindow *_window_ptr, Vector2i _pos, string projectile_type_png)
    : Projectile(_window_ptr, projectile_type_png)
{
    projectile_name = SNOW_PROJECTILE_NAME;
    pos = _pos;
    projectile_sprite.setPosition(_pos.x, _pos.y);
    file_data = read_from_file(2, 2);
    damage = file_data[0];
    speed = file_data[4];
}
