#include "menu.h"

Menu::Menu() {
    gameFont.loadFromFile("../assets/fonts/Nabla.ttf");
    scoreText.setFont(gameFont);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setCharacterSize(30);
    scoreText.setPosition(50, 20);
    scoreText.setString("Scores: " + std::to_string(0));

    livesText.setFont(gameFont);
    livesText.setFillColor(sf::Color::Blue);
    livesText.setCharacterSize(30);
    livesText.setPosition(800, 20);
    livesText.setString("Lives: " + std::to_string(3));

    levelText.setFont(gameFont);
    levelText.setFillColor(sf::Color::Red);
    levelText.setCharacterSize(30);
    levelText.setPosition(400, 20);
    levelText.setString("Level: " + std::to_string(1));

    for (int i = 0; i < 5; i++) {
        options[i].setFont(gameFont);
        options[i].setFillColor(sf::Color::Green);
        options[i].setCharacterSize(50);
        options[i].setPosition(200, 200 + (i * 100));
    }

    options[0].setString("1. Start a new Game");
    options[1].setString("2. See highscores");
    options[2].setString("3. Help");
    options[3].setString("4. Exit");
    options[4].setString("5. Continue");

    menuBackground.setSize(sf::Vector2f(1000, 700));
    menuBackground.setFillColor(sf::Color(0, 0, 0, 200));
    menuBackground.setPosition(0, 0);
}

void Menu::updateScores(int scores) {
    scoreText.setString("Scores: " + std::to_string(scores));
}

void Menu::updateLives(int lives) {
    livesText.setString("Lives: " + std::to_string(lives));
}

void Menu::updateLevel(int level) {
    levelText.setString("Level: " + std::to_string(level));
}

void Menu::renderGUI(sf::RenderWindow& target_w) {
    target_w.draw(scoreText);
    target_w.draw(livesText);
    target_w.draw(levelText);
}

void Menu::renderMenu(sf::RenderWindow& target_w, bool isPaused = false) {
    target_w.draw(menuBackground);
    for (int i = 0; i < 4; i++) {
        target_w.draw(options[i]);
    }

    if(isPaused)
        target_w.draw(options[4]);
}