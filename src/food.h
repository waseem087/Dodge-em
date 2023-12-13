#include <SFML/Graphics.hpp>
#include <iostream>

#include "player.h"
#include "opponent.h"

class FoodItem {
    public:
        void setPosition(sf::Vector2f position);
        sf::Vector2f getPosition();

        virtual sf::Shape* getAppearance() {return nullptr;};
        void render(sf::RenderWindow&, sf::Shape* appearance);
        void update(sf::Shape*);
        bool collides(Player&, sf::Shape*);
        virtual void givePerk(Player&, int&, Opponent&){};

    private:
        sf::Vector2f position;
        sf::Shape* appearance;
};

class Rect : public FoodItem {
    public:
        Rect(sf::Vector2f size);
        sf::Shape* getAppearance() override;
        void givePerk(Player&, int&, Opponent&) override;
    
    private:
        sf::RectangleShape appearance;
};

class Cir : public FoodItem {
    public:
        Cir(float radius);
        sf::Shape* getAppearance() override;
        void givePerk(Player&, int&, Opponent&) override;
    
    private:
        sf::CircleShape appearance;
};

class Hex : public FoodItem {
    public:
        Hex(float length);
        sf::Shape* getAppearance() override;
        void givePerk(Player&, int&, Opponent&) override;
    
    private:
        sf::CircleShape appearance;
};

class Tri : public FoodItem {
    public:
        Tri(float length);
        sf::Shape* getAppearance() override;
        void givePerk(Player&, int&, Opponent&) override;
    
    private:
        sf::CircleShape appearance;
};