#pragma once
#include "Bonus.h"

class SlowBallBonus : public Bonus {
public:
    SlowBallBonus(float x, float y);
    void apply(Paddle& paddle, Ball& ball, GameState& state) override;
};

