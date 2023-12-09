#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

#include "arena.h"
#include "player.h"

#define TITLE "OOP-Project, Spring-2023"

class Game {
    private:
    sf::Texture bg_texture;
    sf::Sprite background; // Game background sprite

    Arena arena;

    Player player;

    void update(sf::RenderWindow& target_w);
    void handleEvents(sf::Event& e, sf::RenderWindow& target_w);

    public:
    Game();

    void start_game();
};
