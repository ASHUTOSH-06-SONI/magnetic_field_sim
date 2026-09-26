#include <SFML/Graphics.hpp>

int main(){

    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Biot Savart"
    );

    window.setFramerateLimit(60);

    sf::CircleShape cir;
    cir.setRadius(5);

    sf::Vector2f position(400.f, 300.f);
    cir.setPosition(position);

    sf::Vector2f vel(200.f, 0.f);

    float m = 1.0f;
    float q = 1.0f;
    float B = 1.0f;

    sf::Clock clock;

    while(window.isOpen()){

        while(auto event = window.pollEvent()){

            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        sf::Vector2f f_mag(
            q * vel.y * B,
            -q * vel.x * B
        );

        sf::Vector2f accl = f_mag / m;

        vel += accl * dt;
        position += vel * dt;

        cir.setPosition(position);

        window.clear();

        for(int i = 50; i <= 750; i += 50){

            for(int j = 50; j <= 550; j += 50){

                sf::Vector2f start(i, j);
                sf::Vector2f dir(30.f, 0.f);

                sf::Vertex arrow[]{
                    sf::Vertex{.position = start},
                    sf::Vertex{.position = start + dir}
                };

                window.draw(
                    arrow,
                    2,
                    sf::PrimitiveType::Lines
                );
            }
        }

        window.draw(cir);
        window.display();
    }

    return 0;
}