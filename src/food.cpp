#include "food.h"

void FoodItem::setPosition(sf::Vector2f position) {
    this->position = position;
}

sf::Vector2f FoodItem::getPosition() {
    return this->position;
}

void FoodItem::render(sf::RenderWindow& target_w, sf::Shape* appearance) {
    target_w.draw(*appearance);
}

bool FoodItem::collides(Player& player, sf::Shape* target) {
    if (target->getGlobalBounds().intersects(player.getAppearance()->getGlobalBounds())) {
        return true;
    }
    return false;
}

void FoodItem::update(sf::Shape* target) {
    target->setPosition(this->getPosition());
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

sf::Shape* Rect::getAppearance() {
    return &this->appearance;
}

sf::Shape* Cir::getAppearance() {
    return &this->appearance;
}

sf::Shape* Hex::getAppearance() {
    return &this->appearance;
}

sf::Shape* Tri::getAppearance() {
    return &this->appearance;
}

void Rect::givePerk(Player& player, int& score, Opponent& opponent) {
    score += 10;
}

void Cir::givePerk(Player& player, int& score, Opponent& opponent) {
    player.setLives(player.getLives() + 1);
    score += 20;
}

void Hex::givePerk(Player& player, int& score, Opponent& opponent) {
    player.setSpeed(5 * 1.5);
    score += 10;
}

void Tri::givePerk(Player& player, int& score, Opponent& opponent) {
    opponent.getAppearance()->setScale(0, 0);
}