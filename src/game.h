#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

#include "arena.h"
#include "player.h"
#include "opponent.h"

#define TITLE "OOP-Project, Spring-2023"

class Game {
    private:
    sf::Texture bg_texture;
    sf::Sprite background; // Game background sprite
    int level = 1;

    Arena arena;

    Player player;

    //since there can be 2 opponents
    Opponent** opponents;

    void update(sf::RenderWindow& target_w);
    void handleEvents(sf::Event& e, sf::RenderWindow& target_w);
    void control(const sf::Event::KeyEvent& e);

    public:
    Game();
    ~Game();

    void start_game();
};
