#include "system.hpp"

void System::Add_plant(string plant_name)
{
    if (plant_name == "peashooter")
    {
    }
    else if (plant_name == "snowpea")
    {
    }
    else if (plant_name == "kernelPult")
    {
    }
    else if (plant_name == "sunflower")
    {
    }
    else if (plant_name == "walnut")
    {
        Vector2i a;
        a.x = 100;
        a.y = 200;
        // Walnut walnut(&window, Vector2i(100,200));
        Walnut walnut(&window, a);
        walnut.adding_walnut();
        // Walnut *walnut = new Walnut(&window, Vector2i(100,200));
        // plants.push_back(walnut);
        cout << "hi" << endl;
    }
}

void System::run()
{
    while (window.isOpen() && state != EXIT)
    {
        // update();
        render();
        handle_events();
        Add_plant("walnut");
    }
    exit(0);
}
void System::handle_events()
{
    Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case (Event::KeyPressed):
            if (event.key.code == Keyboard::Escape)
            {
                window.close();
                break;
            }
        case(Event::Closed):
            window.close();
        }
    }
}

System::System(State _state)
{
    window.create(VideoMode(WINDOW_LENGTH, WINDOW_WIDTH), "PVZ");
    state = _state;
    if (!background_texture.loadFromFile(PICS_PATH + "Frontyard.png"))
    {
        cerr << "cant upload image!";
    }
    background_sprite.setTexture(background_texture);
    // float scaleX = static_cast<float>(window.getSize().x) / background_texture.getSize().x;
    // float scaleY = static_cast<float>(window.getSize().y) / background_texture.getSize().y;
    // background_sprite.setScale(scaleX, scaleY);
    // window_width = window.getSize().x;
    // window_height = window.getSize().y;
}

void System::render()
{
    window.clear();
    switch (state)
    {
    case (IN_GAME):
        window.draw(background_sprite);
        // for(int)
        break;
    case (WIN_SCREEN):
        break;
    case (GAMEOVER_SCREEN):
        break;
    case (EXIT):
        break;
    default:
        break;
    }
    window.display();
}
