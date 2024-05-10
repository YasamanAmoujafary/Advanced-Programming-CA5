#include "zombie.hpp"
void Zombie::render()
{
    window_ptr->draw(zombie_sprite);
}

NormalZombie::NormalZombie(RenderWindow *_window_ptr, Vector2i _pos)
    : Zombie(_window_ptr)
{
    zombie_pos.x = _pos.x;
    zombie_pos.y = _pos.y;
    zombie_sprite.setPosition(_pos.x, _pos.y);
    if (!zombie_texture.loadFromFile(PICS_PATH + NORMAL_ZOMBIE_PNG))
    {
        cerr << "cant upload image!";
    }
    zombie_sprite.setTexture(zombie_texture);
    zombie_sprite.setScale(1, 1);
    IntRect rect;
    rect.width = 80;
    rect.height = 120;
    zombie_sprite.setTextureRect(rect);
    walking_zombie_animation_poses[0] = 80;
    for (int i = 1; i < 46; i++)
    {
        walking_zombie_animation_poses[i] = walking_zombie_animation_poses[i - 1] + 226;
    }
}

void NormalZombie::update()
{
    Time zombie_animation_elapsed = animation_clock.getElapsedTime();
    if (zombie_animation_elapsed.asMilliseconds() >= 100)
    {
        animation_clock.restart();
        current_animation_rect_number = (current_animation_rect_number + 1) % 46;
        IntRect rect;
        rect.width = 80;
        rect.height = 120;
        rect.left = walking_zombie_animation_poses[current_animation_rect_number];
        zombie_sprite.setTextureRect(rect);
    }
}
