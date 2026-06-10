#pragma once
#include "NormalBlock.h"

class BonusBlock : public NormalBlock {
public:
    BonusBlock(float x, float y, int health);
    void onHit(Ball& ball, BonusManager& bonusManager, int& score) override;
};

