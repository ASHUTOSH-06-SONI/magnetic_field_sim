#include <SFML/Graphics.hpp>
#include <iostream>
int main(){
    sf::RenderWindow window(sf::VideoMode({1280,720}),"from scratch");
    window.setFramerateLimit(60);
    sf::CircleShape cir;
    sf::Vector2f position(400.f, 300.f);
    cir.setPosition(position);
    cir.setRadius(5);
    position.x = 1270.f; 
    position.y = 710.f;
    sf::Vector2f vel(200.f,200.f);
    sf::Clock clock;
    while(window.isOpen()){
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
        position += vel * dt;
        if(position.x<0){
            position.x = 0; 
            vel.x*=-1;
        }if(position.x>1270){
            position.x = 1270; 
            vel.x*=-1;
        }if(position.y<0){
            position.y = 0; 
            vel.y*=-1;
        }if(position.y>710){
            position.y = 710; 
            vel.y*=-1;
        }
        cir.setPosition(position);
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