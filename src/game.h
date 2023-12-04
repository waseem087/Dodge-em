#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
// using namespace std;

#define title "OOP-Project, Spring-2023"
// using namespace sf;

class Game {
    private:
    sf::Texture bg_texture;
    sf::Sprite background; // Game background sprite

    void update(sf::RenderWindow& target_w);
    void handleEvents(sf::Event& e, sf::RenderWindow& target_w);

    public:
    Game();

    void start_game();
};
