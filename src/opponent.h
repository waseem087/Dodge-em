#include <SFML/Graphics.hpp>

#pragma once

#include "car.h"
#include "player.h"

class Opponent : public Car {
    public:
    Opponent();
    void update(sf::Vector2f*) override;
    bool kills(Player& player);
    void control(int level);
    void updateTrack(sf::Vector2f*) override;
};