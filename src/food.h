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
    Rect () {
        std::cout << "Rect constructor called" << std::endl;
    }
    ~Rect () {
        std::cout << "Rect destructor called" << std::endl;
    }
    void initialize(sf::Vector2f size);
    void render(sf::RenderWindow& target_w);
};

class Cir : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Cir () {
        std::cout << "Cir constructor called" << std::endl;
    }
    ~Cir () {
        std::cout << "Cir destructor called" << std::endl;
    }
    void initialize(float radius);
    void render(sf::RenderWindow& target_w);
};

class Hex : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Hex () {
        std::cout << "Hex constructor called" << std::endl;
    }
    ~Hex () {
        std::cout << "Hex destructor called" << std::endl;
    }
    void initialize(float length);
    void render(sf::RenderWindow& target_w);
};

class Tri : public FoodItem {
    private:
    sf::CircleShape appearance;

    public:
    Tri () {
        std::cout << "Tri constructor called" << std::endl;
    }
    ~Tri () {
        std::cout << "Tri destructor called" << std::endl;
    }
    void initialize(float length);
    void render(sf::RenderWindow& target_w);
};