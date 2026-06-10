#pragma once
#include "Bonus.h"

class FastBallBonus : public Bonus {
public:
    FastBallBonus(float x, float y);
    void apply(Paddle& paddle, Ball& ball, GameState& state) override;
};

