#pragma once

#include <SFML/Graphics.hpp>

class Menu {
    private:
    sf::Font gameFont;
    sf::Text scoreText, livesText, levelText;

    public:
    Menu();

    void updateScores(int scores);
    void updateLives(int lives);
    void updateLevel(int level);
    // void display_menu();

    void renderGUI(sf::RenderWindow& target_w);

};
