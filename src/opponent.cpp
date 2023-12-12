#include "opponent.h"

Opponent::Opponent() {
    texture.loadFromFile("../assets/img/opponent/opponent.png");
    appearance.setTexture(texture);
    appearance.setScale(0.5, 0.5);
    current_dir = Direction::Down;
}

void Opponent::update(sf::Vector2f* corners) {
    
        int errorDistance = 5;
    
        //counter clockwise
        //change direction
        if (current_dir == Direction::Right && appearance.getPosition().x >= corners[1].x - errorDistance) {
            current_dir = Direction::Up;
        } else if (current_dir == Direction::Up && appearance.getPosition().y <= corners[0].y + errorDistance) {
            current_dir = Direction::Left;
        } else if (current_dir == Direction::Left && appearance.getPosition().x <= corners[3].x + errorDistance) {
            current_dir = Direction::Down;
        } else if (current_dir == Direction::Down && appearance.getPosition().y >= corners[2].y - errorDistance) {
            current_dir = Direction::Right;
        }
    
        move();
}

bool Opponent::kills(Player& player) {
    if (this->getAppearance()->getGlobalBounds().intersects(player.getAppearance()->getGlobalBounds())) {
        player.setAlive(false);
        return true;
    }
    return false;
}
