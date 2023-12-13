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