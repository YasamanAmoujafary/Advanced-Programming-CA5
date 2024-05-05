#include "includes.hpp"

enum State{
    IN_GAME,
    WIN_SCREEN,
    GAMEOVER_SCREEN,
    EXIT
};

class System{
public:
    System(int width, int height);
    void run();
    ~System();
    RenderWindow window;

private:
    State state;
    void update();
    void render();
    void handle_mouse_event();
};