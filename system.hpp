#include "plant.hpp"

enum State{
    IN_GAME,
    WIN_SCREEN,
    GAMEOVER_SCREEN,
    EXIT
};

class System{
public:
    System( State _state);
    void run();
    //~System();
    RenderWindow window;
    void Add_plant()
    {
       // Plant plant(&window);
    }
private:
    int window_width;
    int window_height;
    vector <Plant *> plants;
    State state;
    Texture background_texture;
    Sprite background_sprite;
    //void update();
    void render();
    void handle_events();
};