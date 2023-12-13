#pragma once

#include <SFML/Graphics.hpp>

class Menu {
    private:
    sf::Font gameFont;
    sf::Text scoreText, livesText, levelText, highScores, helpText;
    sf::Text options[5];
    sf::RectangleShape menuBackground;

    public:
    Menu();

    void updateScores(int scores);
    void updateLives(int lives);
    void updateLevel(int level);
    void updateHighScores(int scores);
    // void display_menu();

    void renderGUI(sf::RenderWindow& target_w);
    void renderMenu(sf::RenderWindow& target_w, bool isPaused);
    void renderHighScores(sf::RenderWindow& target_w);
    void renderHelp(sf::RenderWindow& target_w);

};
