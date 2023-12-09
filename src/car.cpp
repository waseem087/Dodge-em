#include "car.h"

sf::Sprite* Car::getAppearance() {
    return &appearance;
}

void Car::initialize(sf::Vector2f pos) {
    appearance.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    appearance.setScale(0.05, 0.05);
    current_dir = Direction::Left;
    appearance.setPosition(pos);
}

void Car::render(sf::RenderWindow& target_w) {
    target_w.draw(appearance);
}

void Car::move() {

    sf::Vector2i dirVector = {0, 0};

    switch (current_dir) {
        case Up:
            dirVector.x = 0;
            dirVector.y = -1;
            break;
            
        case Down:
            dirVector.x = 0;
            dirVector.y = 1;
            break;

        case Left:
            dirVector.x = -1;
            dirVector.y = 0;
            break;

        case Right:
            dirVector.x = 1;
            dirVector.y = 0;
            break;
    }

    this->appearance.move(speed * dirVector.x, speed * dirVector.y);
}

void Car::setSpeed(float value) {
    speed = value;
}

void Car::setTrackID(int value) {
    trackID = value;
}

int Car::getTrackID() {
    return trackID;
}