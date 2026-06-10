#include "Bonus.h"
#include "Config.h"

Bonus::Bonus(float x, float y, sf::Color color)
    : position{ x, y }, speed(Config::BONUS_SPEED), active(true) {
    shape.setSize({ Config::BONUS_SIZE, Config::BONUS_SIZE });
    shape.setOrigin({ Config::BONUS_HALF_SIZE, Config::BONUS_HALF_SIZE });
    shape.setFillColor(color);
    shape.setPosition(position);
}

void Bonus::update(float dt) {
    position.y += speed * dt;
    shape.setPosition(position);
    if (position.y > Config::WINDOW_HEIGHT) active = false;
}

void Bonus::draw(sf::RenderWindow& window) {
    if (active) window.draw(shape);
}

sf::FloatRect Bonus::getBounds() const {
    return sf::FloatRect(position - sf::Vector2f(Config::BONUS_HALF_SIZE, Config::BONUS_HALF_SIZE),
        { Config::BONUS_SIZE, Config::BONUS_SIZE });
}

