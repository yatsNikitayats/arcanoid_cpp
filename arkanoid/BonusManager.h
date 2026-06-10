#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Bonus.h"   

class Paddle;
class Ball;
struct GameState;

class BonusManager {
public:
    void spawn(float x, float y);
    void update(float dt);
    void draw(sf::RenderWindow& window);
    void handlePaddleCollision(Paddle& paddle, Ball& ball, GameState& state);

private:
    std::vector<std::unique_ptr<Bonus>> bonuses;
};

