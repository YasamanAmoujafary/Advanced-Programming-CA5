#include "system.hpp"

System::System(State _state)
{
    dragged_object = NULL;
    state = _state;
    set_background();
}
void System::run()
{
    while (window.isOpen() && state != EXIT)
    {
        update();
        render();
        handle_events();
    }
    exit(0);
}

void System::handle_cooldown()
{
    for (auto item_bar_object : item_bar_objects)
    {
        if (item_bar_object->get_is_in_cooldown())
            item_bar_object->update_cooldown();
    }
    for (auto item_bar_object : item_bar_objects)
    {
        if (item_bar_object->get_is_in_cooldown())
        {
            item_bar_object->set_cool_downed_plant_png();
        }
        else
        {
            item_bar_object->set_normal_plant_png();
        }
    }
}

void System::handle_plant_updates()
{
      for (auto plant : plants)
    {
        //plant->update(projectiles);
    }
}

void System::update()
{
    handle_cooldown();
    handle_plant_updates();
}
void System::handle_events()
{
    Event event;
    Vector2i initial_pos;
    Vector2i final_pos;
    while (window.pollEvent(event))
    {
        bool pressed = false;
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
                Vector2i mousePosition = Mouse::getPosition(window);
                if (mousePosition.x > 0 && mousePosition.x < ITEM_BAR_LENGTH)
                {
                    if (mousePosition.y > FIRST_ITEM_BAR_POS_Y && mousePosition.y < SECOND_ITEM_BAR_POS_Y)
                    {
                        dragged_object = new Sunflower(&window, SUNFLOWER_PNG, Vector2i(0, FIRST_ITEM_BAR_POS_Y));
                    }
                    else if (mousePosition.y > SECOND_ITEM_BAR_POS_Y && mousePosition.y < THIRD_ITEM_BAR_POS_Y)
                    {
                        dragged_object = new Walnut(&window, WALLNUT_PNG, Vector2i(0, SECOND_ITEM_BAR_POS_Y));
                    }
                    else if (mousePosition.y > THIRD_ITEM_BAR_POS_Y && mousePosition.y < FORTH_ITEM_BAR_POS_Y)
                    {
                        dragged_object = new PeaShooter(&window, PEASHOOTER_PNG, Vector2i(0, THIRD_ITEM_BAR_POS_Y));
                    }
                    else if (mousePosition.y > FORTH_ITEM_BAR_POS_Y && mousePosition.y < FIFTH_ITEM_BAR_POS_Y)
                    {
                        dragged_object = new Snowpea(&window, SNOWPEA_PNG, Vector2i(0, FORTH_ITEM_BAR_POS_Y));
                    }
                    else if (mousePosition.y > FIFTH_ITEM_BAR_POS_Y && mousePosition.y < ITEM_BAR_WEIDTH + FIRST_ITEM_BAR_POS_Y)
                    {
                        dragged_object = new Watermelon(&window, WATERMELON_PNG, Vector2i(0, FORTH_ITEM_BAR_POS_Y));
                    }
                }
            }
            break;

        case (Event::MouseButtonReleased):
            if (event.mouseButton.button == Mouse::Left && dragged_object != NULL)
            {
                Vector2i mousePosition = Mouse::getPosition(window);
                pair<Vector2i, bool> center_pos_and_if_in_board;
                center_pos_and_if_in_board = get_center_block_position(mousePosition);
                if (center_pos_and_if_in_board.second)
                {
                    dragged_object->change_pos(center_pos_and_if_in_board.first.x, center_pos_and_if_in_board.first.y);
                    for (auto item_bar_object : item_bar_objects)
                    {
                        if (item_bar_object->get_plant_name() == dragged_object->get_plant_name() && !item_bar_object->get_is_in_cooldown())
                        {
                            item_bar_object->start_timer();
                            item_bar_object->change_is_in_cooldown();
                            plants.push_back(dragged_object);
                        }
                    }
                    dragged_object = NULL;
                }
                break;
            }
        }
    }
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
    float scaleX = static_cast<float>(ITEM_BAR_LENGTH) / (item_bar_texture.getSize().x);
    float scaleY = static_cast<float>(ITEM_BAR_WEIDTH) / (item_bar_texture.getSize().y);
    item_bar_sprite.setScale(scaleX, scaleY);
    item_bar_sprite.setPosition(0, 50);

    adding_item_bar_objects();
    // float scalex = static_cast<float>(window.getSize().x) / background_texture.getSize().x;
    // float scaley = static_cast<float>(window.getSize().y) / background_texture.getSize().y;
    // background_sprite.setScale(scalex, scaley);
}
void System::adding_item_bar_objects()
{
    PeaShooter *peashooter = new PeaShooter(&window, PEASHOOTER_PNG, Vector2i(0, THIRD_ITEM_BAR_POS_Y));
    Snowpea *snowpea = new Snowpea(&window, SNOWPEA_PNG, Vector2i(0, FORTH_ITEM_BAR_POS_Y));
    Sunflower *sunflower = new Sunflower(&window, SUNFLOWER_PNG, Vector2i(0, FIRST_ITEM_BAR_POS_Y));
    Walnut *walnut = new Walnut(&window, WALLNUT_PNG, Vector2i(0, SECOND_ITEM_BAR_POS_Y));
    Watermelon *watermelon = new Watermelon(&window, WATERMELON_PNG, Vector2i(0, FIFTH_ITEM_BAR_POS_Y));
    item_bar_objects.push_back(peashooter);
    item_bar_objects.push_back(snowpea);
    item_bar_objects.push_back(sunflower);
    item_bar_objects.push_back(walnut);
    item_bar_objects.push_back(watermelon);
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
            plant->render(RECT_LENGTH, RECT_WEIDTH);
        }
        for (auto item_bar_object : item_bar_objects)
        {
            item_bar_object->render(ITEM_BAR_LENGTH, ITEM_BAR_WEIDTH / NUM_OF_ITEMS);
        }

        // for (auto plant : plants)
        // {
        //     Sprite p;
        //     p = plant->get_plant_sprite();
        //     p.setPosition(plant->get_pos().x, plant->get_pos().y);
        //     window.draw(p);
        //     p.move(100, 0);
        //     window.draw(p);
        // }
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

void System::make_map()
{
    vector<vector<pair<Vector2i, bool>>> tempMap(NUM_OF_VERTICAL_BLOCKS);
    vector<pair<Vector2i, bool>> temp_horizental(NUM_OF_HORIZENTAL_BLOCKS);
    for (int i = 0; i < tempMap.size(); i++)
    {
        for (int j = 0; j < temp_horizental.size(); j++)
        {
            temp_horizental[j].first.x = BLOCK_TOP_LEFT_CORNER_X + j * RECT_LENGTH;
            temp_horizental[j].first.y = BLOCK_TOP_LEFT_CORNER_Y + i * RECT_WEIDTH;
            temp_horizental[j].second = false;
        }
        tempMap[i] = temp_horizental;
    }
    Map = new vector<vector<pair<Vector2i, bool>>>(tempMap);
    //    for(int i = 0; i < Map->size(); i++)
    // {
    //     for(int j = 0; j <(*Map)[i].size(); j++)
    //     {
    //         cout<<(*Map)[i][j].first.x<<","<<(*Map)[i][j].first.y<<"and is: "<<(*Map)[i][j].second<<endl;
    //     }
    // }
}

pair<Vector2i, bool> System::get_center_block_position(Vector2i mouse_pos)
{
    Vector2i center_pos;
    bool can_plant_object = false;
    pair<Vector2i, bool> center_pos_and_if_in_board;
    for (int i = 0; i < Map->size(); i++)
    {
        for (int j = 0; j < (*Map)[i].size(); j++)
        {
            if (mouse_pos.x < (*Map)[i][j].first.x + RECT_LENGTH && mouse_pos.x > (*Map)[i][j].first.x && mouse_pos.y < (*Map)[i][j].first.y + RECT_WEIDTH && mouse_pos.y > (*Map)[i][j].first.y)
            {
                if (mouse_pos.x <= PLAY_GROUND_LENGTH && mouse_pos.y <= PLAY_GROUND_WIDTH && (*Map)[i][j].second == false)
                {
                    center_pos.x = (*Map)[i][j].first.x;
                    center_pos.y = (*Map)[i][j].first.y;
                    (*Map)[i][j].second = true;
                    can_plant_object = true;
                }
            }
        }
    }
    center_pos_and_if_in_board.first = center_pos;
    center_pos_and_if_in_board.second = can_plant_object;
    // for (int i = 0; i < Map->size(); i++)
    // {
    //     for (int j = 0; j < (*Map)[i].size(); j++)
    //     {
    //         cout << (*Map)[i][j].first.x << "," << (*Map)[i][j].first.y << endl;
    //     }
    // }

    return center_pos_and_if_in_board;
}
