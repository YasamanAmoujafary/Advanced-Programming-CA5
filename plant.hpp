//#include "utilities.hpp"
#include "projectile.hpp"

class Plant
{
public:
    Plant(RenderWindow *_window_ptr, string _plant_png_path) : window_ptr(_window_ptr)
    {
        plant_png_path = _plant_png_path;
        is_in_cooldown = false; 
    }
    virtual void render(int bg_pos_x, int bg_pos_y) = 0;
    virtual void set_normal_plant_png() = 0;
    virtual void set_cool_downed_plant_png() = 0;
    Vector2i get_pos() { return pos; }
    Sprite get_plant_sprite() { return plant_sprite; }
    void change_pos(int x, int y)
    {
        pos.x = x;
        pos.y = y;
    }
    string get_plant_name() { return plant_name; }
    // void set_time() { plantElapsed = plantClock.getElapsedTime(); };
    // int get_cooldown() { return cooldown; }
    // Time get_plant_elapsed() { return plantElapsed; }
    void start_timer()
    {
        // plantElapsed = plantClock.getElapsedTime();
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
    bool get_is_in_cooldown(){return is_in_cooldown;}
    void change_is_in_cooldown(){is_in_cooldown = true;}

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
    RenderWindow *window_ptr;
    Time plantElapsed;
    Clock plantClock;
    //virtual void update();
    Vector2i pos;
};

class Walnut : public Plant
{
public:
    Walnut(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void set_normal_plant_png() { plant_png_path = WALLNUT_PNG; }
    void set_cool_downed_plant_png() { plant_png_path = WALLNUT_COOLDOWN_PNG; }
    void render(int bg_pos_x, int bg_pos_y);

private:
    //void update();
};

class Sunflower : public Plant
{
public:
    Sunflower(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);
    void set_normal_plant_png() { plant_png_path = SUNFLOWER_PNG; }
    void set_cool_downed_plant_png() { plant_png_path = SUNFLOWER_COOLDOWN_PNG; }

private:
    //void update();
};

class PeaShooter : public Plant
{
public:
    PeaShooter(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);
    void set_normal_plant_png() { plant_png_path = PEASHOOTER_PNG; }
    void set_cool_downed_plant_png() { plant_png_path = PEASHOOTER_COOLDOWN_PNG; }

private:
    //void update();
};

class Snowpea : public Plant
{
public:
    Snowpea(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);
    void set_normal_plant_png() { plant_png_path = SNOWPEA_PNG; }
    void set_cool_downed_plant_png() { plant_png_path = SNOWPEA_COOLDOWN_PNG; }

private:
    //void update();
};

class Watermelon : public Plant
{
public:
    Watermelon(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);
    void set_normal_plant_png() { plant_png_path = WATERMELON_PNG; }
    void set_cool_downed_plant_png() { plant_png_path = WATERMELON_COOLDOWN_PNG; }

private:
    //void update();
};
