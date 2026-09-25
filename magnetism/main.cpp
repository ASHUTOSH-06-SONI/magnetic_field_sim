#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Biot Savart");

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();

        for(int i = 50; i <= 750; i+=50){
            for(int j = 50; j <= 550; j+=50){

                sf::Vector2f start(i, j);
                sf::Vector2f dir(30.f, 0.f);

                sf::Vertex arrow[]{
                    sf::Vertex{.position = start},
                    sf::Vertex{.position = start + dir}
                };

                window.draw(arrow, 2, sf::PrimitiveType::Lines);
            }
        }

        window.display();
    }

    return 0;
}