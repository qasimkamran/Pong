#pragma once

#include "raylib.h"

#include <map>

enum PlayerType {
    P1,
    P2,
    CPU
};

struct PlayerInput {
    KeyboardKey left;
    KeyboardKey right;
};

inline std::map<PlayerType, PlayerInput> inputMap;

inline bool AssignKeys(PlayerType player, KeyboardKey left, KeyboardKey right)
{
    if (left == KEY_NULL || right == KEY_NULL || left == right) return false;

    for (const auto& [otherPlayer, keys] : inputMap) {
        if (otherPlayer != player &&
           (keys.left == left || keys.left == right ||
            keys.right == left || keys.right == right)) {
            return false;
        }
    }

    inputMap[player] = {left, right};
    return true;
}

