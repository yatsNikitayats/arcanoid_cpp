#include "StickyBonus.h"

StickyBonus::StickyBonus(float x, float y)
    : Bonus(x, y, sf::Color::Magenta) {
}

void StickyBonus::apply(Paddle& paddle, Ball& ball, GameState& state) {
    state.stickyEnabled = true;
    active = false;
}

