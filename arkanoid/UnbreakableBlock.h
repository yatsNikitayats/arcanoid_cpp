#pragma once
#include "Block.h"

class UnbreakableBlock : public Block {
public:
    UnbreakableBlock(float x, float y);
    void draw(sf::RenderWindow& window) override;
    bool isDestroyed() const override;
    void onHit(Ball& ball, BonusManager& bonusManager, int& score) override;
    sf::FloatRect getBounds() const override;

private:
    sf::Vector2f position;
    sf::RectangleShape shape;
    float width, height;
};

