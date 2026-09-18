#pragma once

#include "internal/paddle.hpp"

#include "pong.hpp"

class Player
{
public:
    Player(PlayerType type, Paddle paddle)
        : type_(type), paddle_(paddle) {}

    bool AssignPlayerMovementKeys(KeyboardKey leftKey, KeyboardKey rightKey);

    void Update();
    void Render();
    void Reset();

private:
    PlayerType type_;
    Paddle paddle_;

    KeyboardKey leftKey_ = KEY_NULL;
    KeyboardKey rightKey_ = KEY_NULL;

    float moveSpeed_ = 5.0f;
};
