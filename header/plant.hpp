#pragma once
// #include "utilities.hpp"
#include "projectile.hpp"

class Plant
{
public:
    Plant(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos) : window_ptr(_window_ptr)
    {
        pos = _pos;

        plant_png_path = _plant_png_path;
        is_in_cooldown = false;
    }
    virtual void render(int bg_pos_x, int bg_pos_y) = 0;
    virtual void set_normal_plant_png() = 0;
    virtual void set_cool_downed_plant_png() = 0;
    virtual void update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row) = 0;
    Vector2i get_pos() { return pos; }
    Sprite get_plant_sprite() { return plant_sprite; }
    FloatRect get_rect() { return plant_sprite.getGlobalBounds(); }
    void update_health(int damaged){health-=damaged;}
    void change_pos(int x, int y)
    {
        pos.x = x;
        pos.y = y;
        row = 0;
        if (FIRST_BLOCK_TOP_POS_Y <= pos.y && pos.y < SECOND_BLOCK_TOP_POS_Y)
            row = 1;
        if (SECOND_BLOCK_TOP_POS_Y <= pos.y && pos.y < THIRD_BLOCK_TOP_POS_Y)
            row = 2;
        if (THIRD_BLOCK_TOP_POS_Y <= pos.y && pos.y < FORTH_BLOCK_TOP_POS_Y)
            row = 3;
        if (FORTH_BLOCK_TOP_POS_Y <= pos.y && pos.y < FIFTH_BLOCK_TOP_POS_Y)
            row = 4;
        if (FIFTH_BLOCK_TOP_POS_Y <= pos.y && pos.y < FIFTH_BLOCK_DOWN_POS_Y)
            row = 5;
    }
    string get_plant_name() { return plant_name; }
    int get_row() { return row; }
    void start_timer()
    {
        plantClock.restart();
    }
    void update_cooldown()
    {
        plantElapsed = plantClock.getElapsedTime();
        if (cooldown <= plantElapsed.asSeconds())
        {
            is_in_cooldown = false;
        }
    }
    bool get_is_in_cooldown() { return is_in_cooldown; }
    void change_is_in_cooldown() { is_in_cooldown = true; }
    int get_health(){return health;}
protected:
    Texture plant_texture;
    Sprite plant_sprite;
    int health;
    string plant_name;
    string plant_png_path;
    int price;
    int cooldown;
    int hit_rate;
    bool is_in_cooldown;
    int row;
    RenderWindow *window_ptr;
    Time plantElapsed;
    Clock plantClock;
    Vector2i pos;
};

class Walnut : public Plant
{
public:
    Walnut(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void set_normal_plant_png() { plant_png_path = WALLNUT_PNG; }
    void set_cool_downed_plant_png() { plant_png_path = WALLNUT_COOLDOWN_PNG; }
    void render(int bg_pos_x, int bg_pos_y);
    void update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row);

private:
};

class Sunflower : public Plant
{
public:
    Sunflower(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);
    void set_normal_plant_png() { plant_png_path = SUNFLOWER_PNG; }
    void set_cool_downed_plant_png() { plant_png_path = SUNFLOWER_COOLDOWN_PNG; }
    void update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row);

private:
};

class PeaShooter : public Plant
{
public:
    PeaShooter(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);
    void set_normal_plant_png() { plant_png_path = PEASHOOTER_PNG; }
    void set_cool_downed_plant_png() { plant_png_path = PEASHOOTER_COOLDOWN_PNG; }
    void update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row);

private:
};

class SnowPeaShooter : public Plant
{
public:
    SnowPeaShooter(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);
    void set_normal_plant_png() { plant_png_path = SNOW_PEASHOOTER_PNG; }
    void set_cool_downed_plant_png() { plant_png_path = SNOW_PEASHOOTER_COOLDOWN_PNG; }
    void update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row);

private:
};

class Watermelon : public Plant
{
public:
    Watermelon(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);
    void set_normal_plant_png() { plant_png_path = WATERMELON_PNG; }
    void set_cool_downed_plant_png() { plant_png_path = WATERMELON_COOLDOWN_PNG; }
    void update(vector<Projectile *> &projectiles, vector<int> num_zombies_in_row);

private:
};
