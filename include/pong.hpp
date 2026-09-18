#pragma once

#include "raylib.h"

#include <map>
#include <string>

inline constexpr float PADDLE_WIDTH = 100.0f;
inline constexpr float PADDLE_HEIGHT = 20.0f;
inline constexpr float PADDLE_MARGIN = 20.0f;

enum PlayerType {
    P1,
    P2,
    CPU
};

struct PlayerInput {
    KeyboardKey leftKey;
    KeyboardKey rightKey;
};

inline std::map<PlayerType, PlayerInput> inputMap;

inline bool AssignKeys(PlayerType player, KeyboardKey leftKey, KeyboardKey rightKey)
{
    if (leftKey == KEY_NULL || rightKey == KEY_NULL || leftKey == rightKey) return false;

    for (const auto& [otherPlayer, keys] : inputMap) {
        if (otherPlayer != player )
        {
            if (keys.leftKey  == leftKey || keys.leftKey  == rightKey ||
                keys.rightKey == leftKey || keys.rightKey == rightKey)
                return false;
        }
    }

    inputMap[player] = {leftKey, rightKey};
    return true;
}


class Game
{
public:
    Game(float width, float height, int fps)
        : gameResolution_({width, height}), gameFPS_(fps)
    {
        SetStartPositions();
    }

    void SetGameTitle(std::string title) { title_ = title; }
    void SetResolution(float width, float height)
    {
        gameResolution_ = {width, height};
        SetStartPositions();
    }

    Vector2 GetGameResolution() const { return gameResolution_; }
    int GetGameFPS() const { return gameFPS_; }
    Vector2 GetP1Start() const { return p1Start_; }
    Vector2 GetP2Start() const { return p2Start_; }
private:
    void SetStartPositions()
    {
        const float centeredX = (gameResolution_.x - PADDLE_WIDTH) / 2.0f;
        p1Start_ = {centeredX, gameResolution_.y - PADDLE_HEIGHT - PADDLE_MARGIN};
        p2Start_ = {centeredX, PADDLE_MARGIN};
    }

    Vector2 gameResolution_;
    int gameFPS_;

    Vector2 p1Start_;
    Vector2 p2Start_;

    std::string title_ = "Pong";
};
