#include "utilities.hpp"

class Plant
{
public:
    Plant(RenderWindow *_window_ptr, string _plant_png_path) : window_ptr(_window_ptr)
    {
        plant_png_path = _plant_png_path;
        vector<int> file_data;
        file_data = read_from_file(2, 5);
        damage = file_data[0];
        health = file_data[1];
        cooldown = file_data[2];
        hit_rate = file_data[3];
        speed = file_data[4];
        price = file_data[5];
    }
    virtual void render(int bg_pos_x, int bg_pos_y) = 0;
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
    bool is_in_cooldown()
    {
        plantElapsed = plantClock.getElapsedTime();
        // upload the gray pics
        if (cooldown > plantElapsed.asSeconds())
        {
            // pop_back_the_gray_pic
            return true;
        }
        else
        {
            plantClock.restart();
            return false;
        }
    }

protected:
    Texture plant_texture;
    Sprite plant_sprite;
    int health;
    int damage;
    string plant_name;
    string plant_png_path;
    int price;
    int cooldown;
    int speed;
    int hit_rate;
    RenderWindow *window_ptr;
    Time plantElapsed;
    Clock plantClock;
    // void update();
    Vector2i pos;
};

class Walnut : public Plant
{
public:
    Walnut(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    // void set_pic_name() { pic_name = "Wallnut_body.png"; }
    void render(int bg_pos_x, int bg_pos_y);

private:
};

class Sunflower : public Plant
{
public:
    Sunflower(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);

private:
};

class PeaShooter : public Plant
{
public:
    PeaShooter(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);

private:
};

class Snowpea : public Plant
{
public:
    Snowpea(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);

private:
};

class Watermelon : public Plant
{
public:
    Watermelon(RenderWindow *_window_ptr, string _plant_png_path, Vector2i _pos);
    void render(int bg_pos_x, int bg_pos_y);

private:
};
