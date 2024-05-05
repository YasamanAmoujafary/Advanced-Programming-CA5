#include "system.hpp"
//#include "includes.hpp"

int main(){
    Texture background_texture;
    if(!background_texture.loadFromFile(PICS_PATH + "Frontyard.png")){
        cerr <<"cant upload image!";
    }
    Sprite background_sprite;
    background_sprite.setTexture(background_texture);

    RenderWindow window(VideoMode(40, 20) ,"PVZ",Style::Fullscreen);
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape){
                window.close();
            }
        }
        window.clear();
        window.draw(background_sprite);
        window.display();
    }

}