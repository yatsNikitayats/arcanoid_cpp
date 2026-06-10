#include "NormalBlock.h"
#include "Ball.h"
#include "BonusManager.h"
#include "Config.h"

NormalBlock::NormalBlock(float x, float y, int health)
    : position{ x, y }, hp(health), width(Config::BLOCK_WIDTH), height(Config::BLOCK_HEIGHT) {
    shape.setSize({ width, height });
    shape.setOrigin({ width / 2.f, height / 2.f });
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
}

void NormalBlock::draw(sf::RenderWindow& window) {
    if (isDestroyed()) return;
    window.draw(shape);
}

bool NormalBlock::isDestroyed() const {
    return hp <= 0;
}

sf::FloatRect NormalBlock::getBounds() const {
    return sf::FloatRect(position - sf::Vector2f(width / 2.f, height / 2.f), { width, height });
}

void NormalBlock::onHit(Ball& ball, BonusManager& bonusManager, int& score) {
    hp--;
    if (hp == 0) score++;
}

