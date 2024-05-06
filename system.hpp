#include "plant.hpp"

enum State
{
    IN_GAME,
    WIN_SCREEN,
    GAMEOVER_SCREEN,
    EXIT
};

class System
{
public:
    System(State _state);
    void run();
    //~System();
    void Add_plant(string plant_name, int position_x, int position_y);

private:
    RenderWindow window;
    int window_width;
    int window_height;
    vector<Plant *> plants;
    vector<Plant *> item_bar_objects;
    State state;
    Texture background_texture;
    Texture item_bar_texture;
    Sprite background_sprite;
    Sprite item_bar_sprite;
    // void update();
    void render();
    void handle_events();
    void which_item_selected();
    void set_background();
};