#include "system.hpp"
System::System(State _state)
{
    dragged_object = NULL;
    state = _state;
    attack_data = read_from_file(3, 1);
    for (int i = 0; i < attack_data[0] / attack_data[1]; i++)
        time_interval.push_back(i * attack_data[1]);
    for (int i = 0; i < attack_data[0] / attack_data[1]; i++)
        num_zombies_per_phase.push_back(attack_data[2] + attack_data[3] * i);
    current_phase = 0;
    set_background();
    for (int i = 0; i < NUM_OF_ROWS; i++)
    {
        num_zombies_in_row.push_back(0);
    }
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

void System::handle_attack_wave()
{
    if (systemClock.getElapsedTime().asSeconds() >= attack_data[1])
    {
        //  systemElapsed = systemClock.getElapsedTime();
        systemClock.restart();
        current_phase++;
        zombie_arrival_time.clear();
        for (int i = 0; i < num_zombies_per_phase[current_phase - 1]; i++)
        {
            float random_time = get_random_number_between_a_limit(attack_data[1]);
            zombie_arrival_time.push_back(random_time);
        }
        sort(zombie_arrival_time.begin(), zombie_arrival_time.end());
    }

    for (int i = 0; i < zombie_arrival_time.size(); i++)
    {
        if (zombie_arrival_time[i] <= systemClock.getElapsedTime().asSeconds() && zombie_arrival_time[i] != -1)
        {
            int which_random_zombie = get_random_number_between_a_limit(3);
            zombie_arrival_time[i] = -1;
            int block_row[5] = {20, 120, 220, 320, 420};
            int which_random_row_zombie = get_random_number_between_a_limit(6);
            Vector2i zombie_pos;
            zombie_pos.y = block_row[which_random_row_zombie - 1];
            num_zombies_in_row[which_random_row_zombie - 1]++;
            zombie_pos.x = 1000;
            if (which_random_zombie == 1)
                {
                    NormalZombie *normalzombie = new NormalZombie(&window,zombie_pos,which_random_row_zombie);
                    zombies.push_back(normalzombie);
                }
                else
                {
                    GiantZombie *giantzombie = new GiantZombie(&window,zombie_pos,which_random_row_zombie);
                    zombies.push_back(giantzombie);
                }
        }
    }
}

void System::run()
{
    while (window.isOpen() && state != EXIT)
    {
        handle_attack_wave();
        update();
        handle_events();
        render();
    }
    exit(0);
}

void System::update()
{
    handle_cooldown();
    for (auto plant : plants)
    {
        plant->update(projectiles, num_zombies_in_row);
    }
    for (auto projectile : projectiles)
    {
        projectile->update();
    }
    for (auto zombie : zombies)
    {
        zombie->update();
        if (zombie->get_pos_x() <= BLOCK_TOP_LEFT_CORNER_X)
        {
            state = GAMEOVER;
        }
    }
    if (current_phase == attack_data[0] / attack_data[1])
    {
        state = WON;
    }
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
                        dragged_object = new SnowPeaShooter(&window, SNOW_PEASHOOTER_PNG, Vector2i(0, FORTH_ITEM_BAR_POS_Y));
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
    if (!background_texture.loadFromFile(PICS_PATH + FRONTYARD_PNG))
    {
        cerr << "cant upload image!";
    }
    background_sprite.setTexture(background_texture);
    if (!item_bar_texture.loadFromFile(PICS_PATH + ITEM_BAR_PNG))
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
    SnowPeaShooter *snowpeashooter = new SnowPeaShooter(&window, SNOW_PEASHOOTER_PNG, Vector2i(0, FORTH_ITEM_BAR_POS_Y));
    Sunflower *sunflower = new Sunflower(&window, SUNFLOWER_PNG, Vector2i(0, FIRST_ITEM_BAR_POS_Y));
    Walnut *walnut = new Walnut(&window, WALLNUT_PNG, Vector2i(0, SECOND_ITEM_BAR_POS_Y));
    Watermelon *watermelon = new Watermelon(&window, WATERMELON_PNG, Vector2i(0, FIFTH_ITEM_BAR_POS_Y));
    item_bar_objects.push_back(peashooter);
    item_bar_objects.push_back(snowpeashooter);
    item_bar_objects.push_back(sunflower);
    item_bar_objects.push_back(walnut);
    item_bar_objects.push_back(watermelon);
}

void System::render()
{
    window.clear();
    string phase_text;
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
        for (auto projectile : projectiles)
        {
            projectile->render();
        }
        // cout << "current phase is : " << current_phase << endl;
        // cout << "total num of zombies" << zombies.size() << endl;

        for (auto zombie : zombies)
        {
            zombie->render();
        }
        phase_text = "PHASE: " + to_string(current_phase);
        write_phase_text(phase_text);
        // graphically show phase_text;

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
    case (WON):
       
        if (!win_texture.loadFromFile(PICS_PATH + WIN_SCREEN_PNG))
            cerr << "Can't open the file" << endl;
        win_sprite.setTexture(win_texture);
        win_sprite.setScale(0.3,0.3);
        window.draw(win_sprite);
        break;
    case (GAMEOVER):

        if (!lost_texture.loadFromFile(PICS_PATH + GAMEOVER_SCREEN_PNG))
            cerr << "Can't open the file" << endl;
        lost_sprite.setTexture(lost_texture);
        window.draw(lost_sprite);
        break;
    case (EXIT):
        break;
    default:
        break;
    }
    window.display();
}

void System::write_phase_text(string phase_text)
{
    Font font;
    if(!font.loadFromFile(FONTS_PATH + PHASE_FONT_TTF))
    {
        cerr<<"cannot open the file"<<endl;
    }
    Text text;
    text.setFont(font);
    text.setString(phase_text);
    text.setCharacterSize(30);
    text.setFillColor(Color::Black);
    text.setPosition(0,0);
    window.draw(text);

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
