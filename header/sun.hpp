#pragma once
#include "utilities.hpp"

class Sun
{
public:
    Sun(RenderWindow *_window_ptr, Vector2i _pos,bool _in_motion);
    void render();
    void update(int speed);
private:
    Texture texture;
    Sprite sprite;
    Vector2i pos;
    RenderWindow *window_ptr;
    bool in_motion;
    Clock sun_clock;
};