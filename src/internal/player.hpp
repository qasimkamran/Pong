#pragma once

#include "internal/paddle.hpp"

#include "pong.hpp"

class Player
{
public:
    Player(PlayerType type, Paddle paddle)
        : type_(type), paddle_(paddle) {}

    bool AssignPlayerMovementKeys(KeyboardKey up, KeyboardKey down);
    void Update();
    void Render();
    void Reset();

private:
    PlayerType type_;
    Paddle paddle_;

    KeyboardKey up_ = KEY_NULL;
    KeyboardKey down_ = KEY_NULL;

    int moveSpeed_ = 5;
};
