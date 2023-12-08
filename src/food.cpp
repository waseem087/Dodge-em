#include "food.h"

void FoodItem::setPosition(sf::Vector2f position) {
    this->position = position;
}

sf::Vector2f FoodItem::getPosition() {
    return this->position;
}

void Rect::initialize(sf::Vector2f size) {
    this->appearance = sf::RectangleShape(size);
    this->appearance.setFillColor(sf::Color::Red);
}

void Cir::initialize(float radius) {
    this->appearance = sf::CircleShape(radius);
    this->appearance.setFillColor(sf::Color::Green);
}

void Hex::initialize(float length) {
    sf::Color color(255, 213, 128);

    this->appearance = sf::CircleShape(length, 6);
    this->appearance.setFillColor(color);
}

void Tri::initialize(float length) {
    this->appearance = sf::CircleShape(length, 3);
    this->appearance.setFillColor(sf::Color::White);
}

void Rect::render(sf::RenderWindow& target_w) {
    target_w.draw(this->appearance);
}

void Cir::render(sf::RenderWindow& target_w) {
    target_w.draw(this->appearance);
}

void Hex::render(sf::RenderWindow& target_w) {
    target_w.draw(this->appearance);
}

void Tri::render(sf::RenderWindow& target_w) {
    target_w.draw(this->appearance);
}
