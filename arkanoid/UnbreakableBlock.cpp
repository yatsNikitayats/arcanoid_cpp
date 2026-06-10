#include "UnbreakableBlock.h"
#include "Config.h"

UnbreakableBlock::UnbreakableBlock(float x, float y)
    : position{ x, y }, width(Config::BLOCK_WIDTH), height(Config::BLOCK_HEIGHT) {
    shape.setSize({ width, height });
    shape.setOrigin({ width / 2.f, height / 2.f });
    shape.setFillColor(sf::Color(120, 120, 120));
    shape.setPosition(position);
}

void UnbreakableBlock::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool UnbreakableBlock::isDestroyed() const {
    return false;
}

sf::FloatRect UnbreakableBlock::getBounds() const {
    return sf::FloatRect(position - sf::Vector2f(width / 2.f, height / 2.f), { width, height });
}

void UnbreakableBlock::onHit(Ball& ball, BonusManager& bonusManager, int& score) {
    // doesn't do anything
}

