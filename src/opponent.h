#include <SFML/Graphics.hpp>

#include "car.h"
#include "player.h"

class Opponent : public Car {
    public:
    Opponent();
    void update(sf::Vector2f*) override;
    bool kills(Player& player);
};