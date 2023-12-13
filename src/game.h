#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>

#include "arena.h"
#include "player.h"
#include "opponent.h"
#include "menu.h"

#define TITLE "OOP-Project, Spring-2023"

enum GameState {
    MainMenu,
    Playing,
    Paused,
    GameOver,
    Help,
    Highscores
};

class Game {
    private:
    sf::Texture bg_texture, mainMenuT;
    sf::Sprite background, mainMenuS; // Game background sprite
    int level = 1;
    int scores = 0;
    FILE* scoreFile;
    int highscores = 0;

    GameState state = GameState::MainMenu;
    GameState prevState = GameState::MainMenu;
    
    Arena arena;

    Menu menu;

    Player player;

    //since there can be 2 opponents
    Opponent** opponents;

    void update(sf::RenderWindow& target_w);
    void handleEvents(sf::Event& e, sf::RenderWindow& target_w);
    void control(const sf::Event::KeyEvent& e);
    void menuControls(const sf::Event::KeyEvent& e, sf::RenderWindow& target_w);
    void saveHighscores();

    public:
    Game();
    ~Game();
    void resetPerks();
    void resetLevel(sf::RenderWindow& target_w);
    void updateLevel(sf::RenderWindow& target_w);

    void start_game();
};
