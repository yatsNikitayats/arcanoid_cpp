#include "BottomWallBonus.h"

BottomWallBonus::BottomWallBonus(float x, float y)
    : Bonus(x, y, sf::Color::Cyan) {
}

void BottomWallBonus::apply(Paddle& paddle, Ball& ball, GameState& state) {
    state.bottomWall = true;
    active = false;
}

