#include "game.h"

Game::Game() {
    bg_texture.loadFromFile("../assets/img/background.jpg");
    background.setTexture(bg_texture);
    background.setScale(1.25, 1.4);

    //creating 2 pointers to opponents
    opponents = new Opponent* [2];
    opponents[0] = new Opponent();
    opponents[1] = nullptr;
}

Game::~Game() {
    delete opponents[0];
    delete opponents[1];
    delete [] opponents;
}

void Game::update(sf::RenderWindow& target_w) {
    target_w.clear(sf::Color::Black);
    target_w.draw(background);
    this->arena.render(target_w);
    this->player.render(target_w);
    opponents[0]->render(target_w);
    target_w.display();
}

void Game::handleEvents(sf::Event& e, sf::RenderWindow& target_w) {
    switch (e.type) {
        case sf::Event::Closed:
            target_w.close();
            break;
        case sf::Event::KeyPressed:
            control(e.key);
            break;
        default:
            break;
    }
}

void Game::control(const sf::Event::KeyEvent& e) {

    for (int i = 0; i < 4; i++) {
        if (player.getAppearance()->getGlobalBounds().intersects(arena.getArenaTile(i)->getGlobalBounds())) {
            return;
        }
    }

    switch (e.code) {
        case sf::Keyboard::Up:
            if (player.getDirection() == Car::Direction::Left && player.getTrackID() < 3)
                player.setTrackID(player.getTrackID() + 1);
            else if (player.getDirection() == Car::Direction::Right && player.getTrackID() > 0)
                player.setTrackID(player.getTrackID() - 1);
            break;

        case sf::Keyboard::Down:
            if (player.getDirection() == Car::Direction::Left && player.getTrackID() > 0)
                player.setTrackID(player.getTrackID() - 1);
            else if (player.getDirection() == Car::Direction::Right && player.getTrackID() < 3)
                player.setTrackID(player.getTrackID() + 1);
            break;

        case sf::Keyboard::Left:
            if (player.getDirection() == Car::Direction::Up && player.getTrackID() > 0)
                player.setTrackID(player.getTrackID() - 1);
            else if (player.getDirection() == Car::Direction::Down && player.getTrackID() < 3)
                player.setTrackID(player.getTrackID() + 1);
            break;

        case sf::Keyboard::Right:
            if (player.getDirection() == Car::Direction::Up && player.getTrackID() < 3)
                player.setTrackID(player.getTrackID() + 1);
            else if (player.getDirection() == Car::Direction::Down && player.getTrackID() > 0)
                player.setTrackID(player.getTrackID() - 1);
            break;

        default:
            break;
    }

    player.updateTrack(arena.getTrack(player.getTrackID())->getCorners());
    
}

void Game::start_game() {

    sf::RenderWindow gameWindow(sf::VideoMode(1000, 700), TITLE);

    this->arena.initialize(gameWindow);
    this->player.initialize(sf::Vector2f(
        gameWindow.getSize().x / 2,
        arena.getTrack(0)->corner[0].position.y
    ));
    opponents[0]->initialize(sf::Vector2f(
        arena.getTrack(0)->corner[0].position.x,
        gameWindow.getSize().y / 2
    ));

    sf::Clock frameTicks, physicsTicks;
    float fps = 60;

    while (gameWindow.isOpen()) {

        int trackID = player.getTrackID();
        Track* currentTrack = arena.getTrack(trackID);

        float timer = frameTicks.getElapsedTime().asMilliseconds();
        sf::Event e;

        while (gameWindow.pollEvent(e)) {
            handleEvents(e, gameWindow);
        }

        if (physicsTicks.getElapsedTime().asMilliseconds() >= 20 && player.isAlive()) {

            for (int i = 0; i < 2; i++) {
                if (opponents[i] != nullptr) {

                    int oppoTrackID = opponents[i]->getTrackID();
                    Track* oppoTrack = arena.getTrack(oppoTrackID);

                    opponents[i]->update(oppoTrack->getCorners());

                    if (opponents[i]->kills(player))
                        std::cout << "Player killed by opponent " << i << std::endl;
                    
                }
            }

            player.update(currentTrack->getCorners());
            arena.foodConsumption(player);
            
            physicsTicks.restart();
        }

        if (timer >= 1.0 / fps * 1000) {
            update(gameWindow);
            frameTicks.restart();
        }
    }
}