#include "Ball.h"
#include "Config.h"
#include "Utils.h"
#include <cmath>

Ball::Ball() : radius(Config::BALL_RADIUS) {
    shape.setRadius(radius);
    shape.setOrigin({ radius, radius });
    shape.setFillColor(sf::Color::White);
    reset();
}

void Ball::reset() {
    position = { Config::WINDOW_WIDTH / 2.f, Config::WINDOW_HEIGHT / 2.f };
    float angleDeg = rnd(Config::BALL_LAUNCH_ANGLE_MIN, Config::BALL_LAUNCH_ANGLE_MAX);
    float angleRad = angleDeg * 3.14159265358979f / 180.f;
    float speed = Config::BALL_SPEED;
    velocity.x = std::sin(angleRad) * speed;
    velocity.y = -std::cos(angleRad) * speed;
    shape.setPosition(position);
}

void Ball::update(float dt) {
    float stepDt = dt / Config::BALL_SUBSTEPS;
    for (int i = 0; i < Config::BALL_SUBSTEPS; ++i) {
        position += velocity * stepDt;
    }
    shape.setPosition(position);
}

void Ball::draw(sf::RenderWindow& window) {
    shape.setPosition(position);
    window.draw(shape);
}

