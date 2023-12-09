#include <SFML/Graphics.hpp>
#include <iostream>

#include "player.h"

class FoodItem {
    private:
    sf::Vector2f position;
    sf::Shape* appearance;

    public:
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    virtual sf::Shape* getAppearance() {return nullptr;};
    virtual void render(sf::RenderWindow&, sf::Shape* appearance);
    void update(sf::Shape*);
    bool collides(Player&, sf::Shape*);
};

class Rect : public FoodItem {
    private:
    sf::RectangleShape appearance;

    public:
    Rect(sf::Vector2f size);
    sf::Shape* getAppearance() override;
};

class Cir : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Cir(float radius);
    sf::Shape* getAppearance() override;
};

class Hex : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Hex(float length);
    sf::Shape* getAppearance() override;
};

class Tri : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Tri(float length);
    sf::Shape* getAppearance() override;
};