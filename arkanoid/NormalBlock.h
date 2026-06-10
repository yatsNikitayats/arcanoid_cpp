#pragma once
#include "Block.h"

class NormalBlock : public Block {
public:
    NormalBlock(float x, float y, int health);
    void draw(sf::RenderWindow& window) override;
    bool isDestroyed() const override;
    void onHit(Ball& ball, BonusManager& bonusManager, int& score) override;
    sf::FloatRect getBounds() const override;

protected:
    sf::Vector2f position;
    sf::RectangleShape shape;
    int hp;
    float width, height;
};

