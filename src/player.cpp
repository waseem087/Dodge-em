#include "player.h"

Player::Player() {
    texture.loadFromFile("../assets/img/player/player.png");
    appearance.setTexture(texture);
}