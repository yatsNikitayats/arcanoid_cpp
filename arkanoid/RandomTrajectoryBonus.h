#pragma once
#include "Bonus.h"

class RandomTrajectoryBonus : public Bonus {
public:
    RandomTrajectoryBonus(float x, float y);
    void apply(Paddle& paddle, Ball& ball, GameState& state) override;
};

