#include "BonusBlock.h"
#include "Ball.h"
#include "BonusManager.h"

BonusBlock::BonusBlock(float x, float y, int health)
    : NormalBlock(x, y, health) {
    shape.setFillColor(sf::Color::Cyan);
}

void BonusBlock::onHit(Ball& ball, BonusManager& bonusManager, int& score) {
    bool wasDestroyed = (hp == 1);
    NormalBlock::onHit(ball, bonusManager, score);
    if (wasDestroyed && hp == 0) {
        bonusManager.spawn(position.x, position.y);
    }
}

