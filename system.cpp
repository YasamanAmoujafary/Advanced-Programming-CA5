#include "system.hpp"
System::System(State _state)
{
    state = _state;
    set_background();
}

void System::Add_plant(string plant_name, int position_x, int position_y)
{
    if (plant_name == "peashooter")
    {
        PeaShooter *peashooter = new PeaShooter(&window, Vector2i(position_x, position_y));
        plants.push_back(peashooter);
    }
    else if (plant_name == "snowpea")
    {
        // go find good pic
        // Snowpea *snowpea = new Snowpea(&window, Vector2i(position_x, position_y));
        // plants.push_back(snowpea);
    }
    else if (plant_name == "kernelPult")
    {
    }
    else if (plant_name == "sunflower")
    {
        Sunflower *sunflower = new Sunflower(&window, Vector2i(position_x, position_y));
        plants.push_back(sunflower);
    }
    else if (plant_name == "walnut")
    {
        Walnut *walnut = new Walnut(&window, Vector2i(position_x, position_y));
        plants.push_back(walnut);
    }
}

void System::run()
{
    while (window.isOpen() && state != EXIT)
    {
        // update();
        render();
        handle_events();
    }
    exit(0);
}
void System::handle_events()
{
    Event event;
    Vector2i initial_pos;
    Vector2i final_pos;
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
        case (Event::Closed):
            window.close();
        case (Event::MouseButtonPressed):
            if (event.mouseButton.button == Mouse::Left)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                for (int i = 0; i < plants.size(); i++)
                {
                    if (plants[i]->get_pos().x == 0)
                    {

                        plants[i]->change_pos(mousePosition.x, mousePosition.y);
                    }
                }
            }
            break;

            // Check if mouse button is released
            // case (Event::MouseButtonReleased):
            //     if (event.mouseButton.button == Mouse::Left)
            //     {
            //         final_pos = circle.getPosition();
            //         std::cout << "Initial Position: (" << initial_pos.x << ", " << initial_pos.y << ")" << std::endl;
            //         std::cout << "Final Position: (" << final_pos.x << ", " << final_pos.y << ")" << std::endl;
            //         break;
            //     }
        }
    }
}
void System ::which_item_selected()
{
    // not useful now but maybe later
    // for(int i = 0; i < plants.size(); i++)
    // {
    //     if(plants[i]->get_pos().x == 0)
    //     {
    //         cout<<plants[i]->get_pos().y<endl;
    //     }
    // }

    // Vector2i mousePosition = Mouse::getPosition(window);
    //             if (circle1.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    //                 cout << "You selected Circle 1!" << std::endl;
    //             else if (circle2.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    //                 std::cout << "You selected Circle 2!" << std::endl;
    //             else if (circle3.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
    //                 std::cout << "You selected Circle 3!" << std::endl;
    //             else
    //                 std::cout << "You didn't select any object." << std::endl;
}
void System ::set_background()
{
    window.create(VideoMode(WINDOW_LENGTH, WINDOW_WIDTH), "PVZ");
    if (!background_texture.loadFromFile(PICS_PATH + "Frontyard.png"))
    {
        cerr << "cant upload image!";
    }
    background_sprite.setTexture(background_texture);
    if (!item_bar_texture.loadFromFile(PICS_PATH + "Item_Bar.png"))
    {
        cerr << "cant upload image!";
    }
    item_bar_sprite.setTexture(item_bar_texture);
    item_bar_sprite.setScale(1, 1);
    item_bar_sprite.setPosition(0, 250);
    Add_plant("walnut", 0, 350);
    Add_plant("sunflower", 0, 250);
    Add_plant("peashooter", 0, 450);
    Add_plant("snowpea", 0, 550);
    float scaleX = static_cast<float>(window.getSize().x) / background_texture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / background_texture.getSize().y;
    background_sprite.setScale(scaleX, scaleY);
}

void System::render()
{
    window.clear();
    switch (state)
    {
    case (IN_GAME):
        window.draw(background_sprite);
        window.draw(item_bar_sprite);
        for (auto plant : plants)
        {
            plant->render();
        }
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
