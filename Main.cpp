#include <iostream>
#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "test window");
    sf::CircleShape shape(300.f);
    shape.setFillColor(sf::Color(100, 250, 50));
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(shape);
        window.display();
    }
   
    return 0;
}

