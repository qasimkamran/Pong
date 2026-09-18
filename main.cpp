#include "raylib.h"

#include "src/internal/paddle.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Test - CMake Setup");
    SetTargetFPS(60);

    Paddle paddle(0, 0, 100, 50, GREEN);
    const Color paddleColors[] = {RED, BLUE, ORANGE, PURPLE, GREEN};
    int colorIndex = 0;
    double lastColorChange = GetTime();

    while (!WindowShouldClose()) {
        if (GetTime() - lastColorChange >= 3.0) {
            paddle.ColorPaddle(paddleColors[colorIndex]);
            colorIndex = (colorIndex + 1) % 5;
            lastColorChange = GetTime();
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("If you see this, Raylib is working!", 190, 200, 20, LIGHTGRAY);
            paddle.SetPaddlePosition(
                GetMouseX() - paddle.GetWidth() / 2,
                GetMouseY() - paddle.GetHeight() / 2
            );
            paddle.RenderPaddle();
            DrawText("Move your mouse around!", 300, 300, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

