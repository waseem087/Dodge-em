#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "Dodge-em!");

    while(gameWindow.isOpen()) {
        sf::Event event;
        while(gameWindow.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                gameWindow.close();
            }
        }

        gameWindow.clear(sf::Color::Black);
        gameWindow.display();

    }

    return 0;
}