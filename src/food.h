#include <SFML/Graphics.hpp>
#include <iostream>

#include "player.h"
#include "opponent.h"

class FoodItem {
    private:
    sf::Vector2f position;
    sf::Shape* appearance;

    public:
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    virtual sf::Shape* getAppearance() {return nullptr;};
    void render(sf::RenderWindow&, sf::Shape* appearance);
    void update(sf::Shape*);
    bool collides(Player&, sf::Shape*);
    virtual void givePerk(Player&, int&, Opponent&){};
};

class Rect : public FoodItem {
    private:
    sf::RectangleShape appearance;

    public:
    Rect(sf::Vector2f size);
    sf::Shape* getAppearance() override;
    void givePerk(Player&, int&, Opponent&) override;
};

class Cir : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Cir(float radius);
    sf::Shape* getAppearance() override;
    void givePerk(Player&, int&, Opponent&) override;
};

class Hex : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Hex(float length);
    sf::Shape* getAppearance() override;
    void givePerk(Player&, int&, Opponent&) override;
};

class Tri : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Tri(float length);
    sf::Shape* getAppearance() override;
    void givePerk(Player&, int&, Opponent&) override;
};