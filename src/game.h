#pragma once

#include <SFML/Graphics.hpp>
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
        sf::Sprite background, mainMenuS;

        int level = 1;
        int scores = 0;
        int highscores = 0;

        FILE* scoreFile;

        GameState state = GameState::MainMenu;
        GameState prevState = GameState::MainMenu;

        Arena arena;
        Menu menu;
        Player player;
        //since there can be 2 opponents, we can use 1 pointer to point towards both of em
        Opponent** opponents;

        //rendering
        void update(sf::RenderWindow& target_w);
        void handleEvents(sf::Event& e, sf::RenderWindow& target_w);
        //controls player
        void control(const sf::Event::KeyEvent& e);
        void menuControls(const sf::Event::KeyEvent& e, sf::RenderWindow& target_w);
        void saveHighscores();
        void resetPerks();
        void resetLevel(sf::RenderWindow& target_w);
        void updateLevel(sf::RenderWindow& target_w);

        void initialize(sf::RenderWindow& target_w);
        void updateDisplayValues();

    public:
        Game();
        ~Game();
        void start_game();
};
