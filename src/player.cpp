#include "internal/player.hpp"

bool Player::AssignPlayerMovementKeys(KeyboardKey up, KeyboardKey down)
{
    if (!AssignKeys(type_, up, down)) return false;

    up_ = up;
    down_ = down;
    return true;
}
