#include "raylib.h"

#include "internal/player.hpp"

bool Player::AssignPlayerMovementKeys(KeyboardKey leftKey, KeyboardKey rightKey)
{
    if (!AssignKeys(type_, leftKey, rightKey)) return false;

    leftKey_ = leftKey;
    rightKey_ = rightKey;
    return true;
}

void Player::Update()
{
    if (leftKey_ == KEY_NULL || rightKey_ == KEY_NULL)
        return;

    if (IsKeyDown(leftKey_))
        paddle_.MovePaddle(-moveSpeed_, 0.0f);

    if (IsKeyDown(rightKey_))
        paddle_.MovePaddle(moveSpeed_, 0.0f);
}

void Player::Render()
{
    paddle_.RenderPaddle();
}

void Player::Reset()
{
    paddle_.Reset();
}
