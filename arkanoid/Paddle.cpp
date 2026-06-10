#include "Paddle.h"
#include "Config.h"

Paddle::Paddle() { reset(); }

void Paddle::reset() {
    width = Config::PADDLE_DEFAULT_WIDTH;
    height = Config::PADDLE_HEIGHT;
    position = { Config::WINDOW_WIDTH / 2.f, Config::WINDOW_HEIGHT - Config::PADDLE_Y_OFFSET };
    shape.setSize({ width, height });
    shape.setOrigin({ width / 2.f, height / 2.f });
    shape.setFillColor(sf::Color::White);
    shape.setPosition(position);
}

void Paddle::update(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        position.x -= Config::PADDLE_SPEED * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        position.x += Config::PADDLE_SPEED * dt;

    float half = width / 2.f;
    if (position.x < half) position.x = half;
    if (position.x > Config::WINDOW_WIDTH - half) position.x = Config::WINDOW_WIDTH - half;
    shape.setPosition(position);
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Paddle::getBounds() const {
    return sf::FloatRect(position - sf::Vector2f(width / 2.f, height / 2.f), { width, height });
}

