#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

#include "arena.h"
#include "player.h"
#include "opponent.h"
#include "menu.h"

#define TITLE "OOP-Project, Spring-2023"

class Game {
    private:
    sf::Texture bg_texture;
    sf::Sprite background; // Game background sprite
    int level = 1;
    int scores = 0;

    Arena arena;

    Menu menu;

    Player player;

    //since there can be 2 opponents
    Opponent** opponents;

    void update(sf::RenderWindow& target_w);
    void handleEvents(sf::Event& e, sf::RenderWindow& target_w);
    void control(const sf::Event::KeyEvent& e);

    public:
    Game();
    ~Game();
    void resetPerks();
    void updateLevel(sf::RenderWindow& target_w);

    void start_game();
};
