#include <SFML/Graphics.hpp>
#include <iostream>

class FoodItem {
    private:
    sf::Vector2f position;

    public:
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
};

class Rect : public FoodItem {
    private:
    sf::RectangleShape appearance;

    public:
    void initialize(sf::Vector2f size);
    void render(sf::RenderWindow& target_w);
};

class Cir : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    void initialize(float radius);
    void render(sf::RenderWindow& target_w);
};

class Hex : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    void initialize(float length);
    void render(sf::RenderWindow& target_w);
};

class Tri : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    void initialize(float length);
    void render(sf::RenderWindow& target_w);
};