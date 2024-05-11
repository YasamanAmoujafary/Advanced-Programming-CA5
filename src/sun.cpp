#include "sun.hpp"

Sun::Sun(RenderWindow *_window_ptr,Vector2i _pos,bool _in_motion): window_ptr(_window_ptr)
{
    if (!texture.loadFromFile(PICS_PATH + SUN_PNG))
    {
        cerr << "cant upload image!";
    }
    sprite.setTexture(texture);
    sprite.setScale(0.5, 0.5);
    pos = _pos;
    sprite.setPosition(pos.x, pos.y);
    in_motion = _in_motion;
}

void Sun::render()
{
    window_ptr->draw(sprite);
}

void Sun::update(int speed)
{
    if(pos.y <=PLAY_GROUND_WIDTH-sprite.getGlobalBounds().height)
    {
        if(in_motion)
        {
            if (sun_clock.getElapsedTime().asMilliseconds() > 200)
                {
                    sun_clock.restart();
                    pos.y += speed;
                    sprite.setPosition(pos.x, pos.y);
                }
        }
    }
}