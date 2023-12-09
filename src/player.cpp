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
        current_dir = Direction::Down;
    } else if (current_dir == Direction::Down && appearance.getPosition().y >= corners[2].y - errorDistance) {
        current_dir = Direction::Left;
    } else if (current_dir == Direction::Left && appearance.getPosition().x <= corners[3].x + errorDistance) {
        current_dir = Direction::Up;
    } else if (current_dir == Direction::Up && appearance.getPosition().y <= corners[0].y + errorDistance) {
        current_dir = Direction::Right;
    }

    move();

}