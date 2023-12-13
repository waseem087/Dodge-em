#include "opponent.h"

Opponent::Opponent() {
    texture.loadFromFile("../assets/img/opponent/opponent.png");
    appearance.setTexture(texture);
    current_dir = Direction::Down;
    srand(time(0));
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

void Opponent::control(int level) {
    int dir = rand() % 4;
    std::cout << "trackID before: " << trackID << std::endl;

    switch (dir) {
        case 0:     //left
        std::cout << "Direction: Left" << std::endl;
            if (current_dir == Direction::Up && trackID < 3)
                trackID++;
            else if (current_dir == Direction::Down && trackID > 0)
                trackID--;
            break;
        case 1:     //right
            std::cout << "Direction: Right" << std::endl;
            if (current_dir == Direction::Up && trackID > 0)
                trackID--;
            else if (current_dir == Direction::Down && trackID < 3)
                trackID++;
            break;
        case 2:     //up
            std::cout << "Direction: Up" << std::endl;
            if (current_dir == Direction::Left && trackID > 0)
                trackID--;
            else if (current_dir == Direction::Right && trackID < 3)
                trackID++;
            break;
        case 3:     //down
            std::cout << "Direction: Down" << std::endl;
            if (current_dir == Direction::Left && trackID < 3)
                trackID++;
            else if (current_dir == Direction::Right && trackID > 0)
                trackID--;
            break;
        default:
            break;
    }

    std::cout << "trackID after: " << trackID << std::endl;

}

void Opponent::updateTrack(sf::Vector2f* corners) {
    switch (current_dir) {
        case Direction::Up:
            appearance.setPosition(corners[2].x, appearance.getPosition().y);
            break;
        case Direction::Down:
            appearance.setPosition(corners[0].x, appearance.getPosition().y);
            break;
        case Direction::Left:
            appearance.setPosition(appearance.getPosition().x, corners[1].y);
            break;
        case Direction::Right:
            appearance.setPosition(appearance.getPosition().x, corners[3].y);
            break;
    }
}
