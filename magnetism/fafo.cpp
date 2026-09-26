#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(
        sf::VideoMode({1280, 720}),
        "Magnetic Force Experiment"
    );

    window.setFramerateLimit(60);

    sf::CircleShape cir;
    cir.setRadius(5);

    sf::Vector2f position(400.f, 300.f);
    cir.setPosition(position);

    // Initial velocity
    sf::Vector2f vel(200.f, 0.f);

    // Particle properties
    float m = 1.0f;
    float q = 1.0f;

    // Magnetic field perpendicular to screen
    float B = 1.0f;

    sf::Vector2f f_net(0.f, 0.f);
    sf::Vector2f accl(0.f, 0.f);

    sf::Clock clock;

    while (window.isOpen()) {

        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        // Reset net force every frame
        f_net = sf::Vector2f(0.f, 0.f);

        // Magnetic force: F = q(v × B)
        sf::Vector2f f_mag(
            q * vel.y * B,
            -q * vel.x * B
        );

        f_net += f_mag;

        // Newton's second law
        accl = f_net / m;

        // Update velocity and position
        vel += accl * dt;
        position += vel * dt;

        // Events
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        cir.setPosition(position);

        window.clear();
        window.draw(cir);
        window.display();
    }

    return 0;
}