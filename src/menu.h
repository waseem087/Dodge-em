#pragma once

#include <SFML/Graphics.hpp>

class Menu {
    private:
    sf::Font gameFont;
    sf::Text scoreText, livesText, levelText;
    sf::Text options[5];
    sf::RectangleShape menuBackground;

    public:
    Menu();

    void updateScores(int scores);
    void updateLives(int lives);
    void updateLevel(int level);
    // void display_menu();

    void renderGUI(sf::RenderWindow& target_w);
    void renderMenu(sf::RenderWindow& target_w, bool isPaused);
};
