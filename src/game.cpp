#include "game.h"

Game::Game() {
    bg_texture.loadFromFile("../assets/img/background.jpg");
    background.setTexture(bg_texture);
    background.setScale(1.25, 1.4);
}

void Game::update(sf::RenderWindow& target_w) {
    target_w.clear(sf::Color::Black);
    target_w.draw(background);
    this->arena.render(target_w);
    this->player.render(target_w);
    target_w.display();
}

void Game::handleEvents(sf::Event& e, sf::RenderWindow& target_w) {
    switch (e.type) {
        case sf::Event::Closed:
            target_w.close();
            break;
        default:
            break;
    }
}

void Game::start_game() {

    sf::RenderWindow gameWindow(sf::VideoMode(1000, 700), TITLE);

    this->arena.initialize(gameWindow);
    this->player.initialize(sf::Vector2f(
        gameWindow.getSize().x / 2,
        arena.getTrack(0)->corner[0].position.y
    ));

    sf::Clock frameTicks, physicsTicks;
    float fps = 60;

    while (gameWindow.isOpen()) {

        float timer = frameTicks.getElapsedTime().asMilliseconds();
        sf::Event e;

        while (gameWindow.pollEvent(e)) {
            handleEvents(e, gameWindow);
        }

        if (physicsTicks.getElapsedTime().asMilliseconds() >= 200) {
            physicsTicks.restart();
        }

        if (timer >= 1.0 / fps * 1000) {
            update(gameWindow);
            frameTicks.restart();
        }
    }
}