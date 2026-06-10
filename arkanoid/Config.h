#pragma once

namespace Config {
   
    constexpr int WINDOW_WIDTH = 1000;
    constexpr int WINDOW_HEIGHT = 700;

    
    constexpr float BALL_RADIUS = 10.f;
    constexpr float BALL_SPEED = 250.f;
    constexpr int BALL_SUBSTEPS = 5;
    constexpr float BALL_STICKY_OFFSET = 30.f;        
    constexpr float BALL_LAUNCH_ANGLE_MIN = -35.f;    
    constexpr float BALL_LAUNCH_ANGLE_MAX = 35.f;

    
    constexpr float PADDLE_DEFAULT_WIDTH = 140.f;
    constexpr float PADDLE_HEIGHT = 20.f;
    constexpr float PADDLE_Y_OFFSET = 40.f;           
    constexpr float PADDLE_SPEED = 500.f;
    constexpr float MAX_PADDLE_WIDTH = 300.f;
    constexpr float MIN_PADDLE_WIDTH = 60.f;

    
    constexpr float BLOCK_WIDTH = 72.f;
    constexpr float BLOCK_HEIGHT = 28.f;
    constexpr float BLOCK_GAP = 1.f;
    constexpr int BLOCK_ROWS = 6;
    constexpr int BLOCK_COLS = 12;
    constexpr float BLOCK_START_X = 50.f;
    constexpr float BLOCK_START_Y = 60.f;

    
    constexpr float BONUS_SIZE = 24.f;
    constexpr float BONUS_SPEED = 240.f;
    constexpr float BONUS_HALF_SIZE = BONUS_SIZE / 2.f; 

    
    constexpr float PADDLE_HIT_FORCE = 500.f;
    constexpr float MAX_BALL_SPEED = 900.f;
    constexpr float SPEED_BLOCK_MULTIPLIER = 1.15f;
    constexpr float FAST_BALL_MULTIPLIER = 1.3f;
    constexpr float SLOW_BALL_MULTIPLIER = 0.8f;

    
    constexpr float BIG_PADDLE_INCREMENT = 40.f;
    constexpr float SMALL_PADDLE_DECREMENT = 30.f;

    
    constexpr float BALL_BOUNCE_CORRECTION = 1.f;      
    constexpr float BOTTOM_WALL_REBOUND_Y_OFFSET = 10.f;

    
    constexpr float RANDOM_ANGLE_MIN = -60.f;
    constexpr float RANDOM_ANGLE_MAX = 60.f;
}

