#include <SFML/Graphics.hpp>
#include <iostream>
int main(){
    sf::RenderWindow window(sf::VideoMode({1280,720}),"from scratch");
    window.setFramerateLimit(60);
    sf::CircleShape cir;
    cir.setPosition(sf::Vector2f(400.f,300.f));
    cir.setRadius(5);

    while(window.isOpen()){
        while(auto event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        window.clear();
        window.draw(cir);
        window.display();
    }
    return 0;
}