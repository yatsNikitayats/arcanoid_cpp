#pragma once
#include <SFML/Graphics.hpp>

class Ball;
class BonusManager;

class Block {
public:
    virtual ~Block() = default;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual bool isDestroyed() const = 0;
    virtual void onHit(Ball& ball, BonusManager& bonusManager, int& score) = 0;
    virtual sf::FloatRect getBounds() const = 0;
};

