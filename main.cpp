#include "pong.hpp"
#include "raylib.h"

#include "src/internal/paddle.hpp"
#include "src/internal/player.hpp"

int main() {
    Game game(800, 600, 60);

    Vector2 resolution = game.GetGameResolution();

    InitWindow(static_cast<int>(resolution.x), static_cast<int>(resolution.y), "Pong");
    SetTargetFPS(game.GetGameFPS());

    Vector2 p1Start = game.GetP1Start();
    Vector2 p2Start = game.GetP2Start();

    Paddle paddle1(p1Start.x, p1Start.y, PADDLE_WIDTH, PADDLE_HEIGHT, GREEN);
    Paddle paddle2(p2Start.x, p2Start.y, PADDLE_WIDTH, PADDLE_HEIGHT, RED);

    Player p1(PlayerType::P1, paddle1);
    Player p2(PlayerType::CPU, paddle2);

    p1.AssignPlayerMovementKeys(KEY_LEFT, KEY_RIGHT);

    constexpr const char* title = "Pong!";
    constexpr int titleFontSize = 20;
    const int titleX = (static_cast<int>(resolution.x) - MeasureText(title, titleFontSize)) / 2;
    const int titleY = (static_cast<int>(resolution.y) - titleFontSize) / 2;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(title, titleX, titleY, titleFontSize, LIGHTGRAY);
            p1.Update();
            p1.Render();

            p2.Update();
            p2.Render();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
