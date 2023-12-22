#include "player.h"

Player::Player() {
    texture.loadFromFile("../assets/img/player/player.png");
    appearance.setTexture(texture);
    current_dir = Direction::Right;
}

void Player::update(sf::Vector2f* corners) {

    int errorDistance = 5;

    //clockwise
    //change direction
    if (current_dir == Direction::Right && appearance.getPosition().x >= corners[1].x - errorDistance) {
        appearance.setRotation(90);
        current_dir = Direction::Down;
    }
    if (current_dir == Direction::Down && appearance.getPosition().y >= corners[2].y - errorDistance) {
        appearance.setRotation(180);
        current_dir = Direction::Left;
    }
    if (current_dir == Direction::Left && appearance.getPosition().x <= corners[3].x + errorDistance) {
        appearance.setRotation(270);
        current_dir = Direction::Up;
    }
    if (current_dir == Direction::Up && appearance.getPosition().y <= corners[0].y + errorDistance) {
        appearance.setRotation(0);
        current_dir = Direction::Right;
    }

    move();

}

void Player::updateTrack(sf::Vector2f* corners) {
    switch (current_dir) {
        case Direction::Up:
            appearance.setPosition(corners[0].x, appearance.getPosition().y);
            break;
        case Direction::Down:
            appearance.setPosition(corners[2].x, appearance.getPosition().y);
            break;
        case Direction::Left:
            appearance.setPosition(appearance.getPosition().x, corners[3].y);
            break;
        case Direction::Right:
            appearance.setPosition(appearance.getPosition().x, corners[1].y);
            break;
    }
}

bool Player::isAlive() {
    return alive;
}

void Player::setAlive(bool alive) {
    this->alive = alive;
}

int Player::getLives() {
    return lives;
}

void Player::setLives(int lives) {
    this->lives = lives;
}
