#include "food.h"

void FoodItem::setPosition(sf::Vector2f position) {
    this->position = position;
}

sf::Vector2f FoodItem::getPosition() {
    return this->position;
}

Rect::Rect(sf::Vector2f size) {
    this->appearance = sf::RectangleShape(size);
    this->appearance.setFillColor(sf::Color::Red);
    this->appearance.setOrigin(size.x/2, size.y/2);
}

Cir::Cir(float radius) {
    this->appearance = sf::CircleShape(radius);
    this->appearance.setFillColor(sf::Color::Green);
    this->appearance.setOrigin(radius, radius);
}

Hex::Hex(float length) {
    sf::Color color(255, 213, 128);

    this->appearance = sf::CircleShape(length, 6);
    this->appearance.setFillColor(color);
    this->appearance.setOrigin(length, length);
}

Tri::Tri(float length) {
    this->appearance = sf::CircleShape(length, 3);
    this->appearance.setFillColor(sf::Color::White);
    this->appearance.setOrigin(length, length);
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

void Rect::update() {
    this->appearance.setPosition(this->getPosition());
}

void Cir::update() {
    this->appearance.setPosition(this->getPosition());
}

void Hex::update() {
    this->appearance.setPosition(this->getPosition());
}

void Tri::update() {
    this->appearance.setPosition(this->getPosition());
}