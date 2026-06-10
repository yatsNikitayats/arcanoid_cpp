#include "Game.h"
#include "Physics.h"
#include "CollisionManager.h"
#include "Config.h"
#include "Utils.h"
#include <cmath>

Game::Game()
    : window(sf::VideoMode({ Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT }), "Arkanoid")
    , score(0), lives(3), stickyEnabled(false), ballAttached(false), bottomWall(false) {
    window.setFramerateLimit(144);
}

void Game::resetRound() {
    ball.reset();
    paddle.reset();
    stickyEnabled = false;
    ballAttached = false;
    bottomWall = false;
}

void Game::update(float dt) {
    paddle.update(dt);

    if (!ballAttached) {
        ball.update(dt);
    }
    else {
        ball.position.x = paddle.position.x;
        ball.position.y = paddle.position.y - Config::BALL_STICKY_OFFSET;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            ballAttached = false;
            float angleDeg = rnd(Config::BALL_LAUNCH_ANGLE_MIN, Config::BALL_LAUNCH_ANGLE_MAX);
            float angleRad = angleDeg * 3.14159265358979f / 180.f;
            float speed = Config::BALL_SPEED;
            ball.velocity.x = std::sin(angleRad) * speed;
            ball.velocity.y = -std::cos(angleRad) * speed;
        }
    }

    Physics::handleWallCollision(ball);
    Physics::handlePaddleCollision(ball, paddle, stickyEnabled, ballAttached);

    int addedScore = 0;
    CollisionManager::handleBlockCollisions(ball, level, bonusManager, addedScore);
    score += addedScore;

    bonusManager.update(dt);
    GameState state{ stickyEnabled, bottomWall, ballAttached };
    bonusManager.handlePaddleCollision(paddle, ball, state);
    stickyEnabled = state.stickyEnabled;
    bottomWall = state.bottomWall;
    ballAttached = state.ballAttached;

    if (ball.position.y - ball.radius > Config::WINDOW_HEIGHT) {
        if (bottomWall) {
            bottomWall = false;
            ball.velocity.y = -std::abs(ball.velocity.y);
            ball.position.y = Config::WINDOW_HEIGHT - ball.radius - Config::BOTTOM_WALL_REBOUND_Y_OFFSET;
        }
        else {
            lives--;
            resetRound();
            if (lives <= 0) {
                lives = 3;
                score = 0;
                level.generate();
            }
        }
    }
}

void Game::render() {
    window.clear(sf::Color::Black);
    level.draw(window);
    bonusManager.draw(window);
    paddle.draw(window);
    ball.draw(window);
    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        update(dt);
        render();
    }
}

