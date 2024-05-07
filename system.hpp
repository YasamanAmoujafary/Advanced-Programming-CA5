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
    void make_map();

private:
    RenderWindow window;
    int window_width;
    int window_height;
    vector<Plant *> plants;
    vector<Plant *> item_bar_objects;
    Plant *dragged_object;
    State state;
    Texture background_texture;
    Texture item_bar_texture;
    Sprite background_sprite;
    Sprite item_bar_sprite;
    vector<vector<pair<Vector2i, bool>>> *Map;
    bool is_bar_item_planted;
    void update();
    void render();
    void handle_events();
    void set_background();
    void adding_item_bar_objects();
    pair<Vector2i, bool> get_center_block_position(Vector2i mouse_pos);
};