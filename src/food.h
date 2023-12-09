#include <SFML/Graphics.hpp>
#include <iostream>

#include "player.h"

class FoodItem {
    private:
    sf::Vector2f position;

    public:
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    virtual void render(sf::RenderWindow&) {};
    virtual void update() {};
    virtual bool collides(Player&){return false;};
};

class Rect : public FoodItem {
    private:
    sf::RectangleShape appearance;

    public:
    Rect(sf::Vector2f size);
    void render(sf::RenderWindow& target_w) override;
    void update() override;
    bool collides(Player& player) override;
};

class Cir : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Cir(float radius);
    void render(sf::RenderWindow& target_w) override;
    void update() override;
    bool collides(Player& player) override;
};

class Hex : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Hex(float length);
    void render(sf::RenderWindow& target_w) override;
    void update() override;
    bool collides(Player& player) override;
};

class Tri : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Tri(float length);
    void render(sf::RenderWindow& target_w) override;
    void update() override;
    bool collides(Player& player) override;
};