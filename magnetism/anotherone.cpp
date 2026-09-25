#include <SFML/Graphics.hpp>
#include <iostream>
int main(){
    sf::RenderWindow window(sf::VideoMode({1280,720}),"from scratch");
    window.setFramerateLimit(60);
    sf::CircleShape cir;
    sf::Vector2f position(400.f, 300.f);
   
    cir.setPosition(position);
    cir.setRadius(5);
   
    sf::Vector2f vel(200.f,200.f);
    sf::Vector2f grav(0.f,981.f);
    sf::Clock clock;

    float m = 981.f;
    float eta = 0.01f;
    float r = 5.0f;
    float q = -1.0f;
    sf::Vector2f g_force= grav*m;
    sf::Vector2f f_net(0.f,0.f);
    f_net+=g_force;
    sf::Vector2f accl = f_net/m;
    sf::Vector2f drag = -6.0f * 3.14159265f * eta * r * vel;
    f_net+=drag;
    sf::Vector2f E(0.f,-500.f);
    sf::Vector2f f_elec = q*E;
    f_net+=f_elec;
    float B = 1.0f;
    sf::Vector2f r_mag(q*vel.y*B,-q*vel.x*B);
    f_net+=r_mag;
    while(window.isOpen()){
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
        vel += grav * dt;
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