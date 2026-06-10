#pragma once
#include "Bonus.h"

class StickyBonus : public Bonus {
public:
    StickyBonus(float x, float y);
    void apply(Paddle& paddle, Ball& ball, GameState& state) override;
};

