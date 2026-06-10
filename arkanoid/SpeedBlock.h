#pragma once
#include "NormalBlock.h"

class SpeedBlock : public NormalBlock {
public:
    SpeedBlock(float x, float y, int health);
    void onHit(Ball& ball, BonusManager& bonusManager, int& score) override;
};

