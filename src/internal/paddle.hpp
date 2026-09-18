#pragma once

#include "raylib.h"

class Paddle
{
public:
    Paddle(int x, int y, int width, int height, Color color)
        : startX_(x), startY_(y), posX_(x), posY_(y),
          width_(width), height_(height), color_(color) {}

    void RenderPaddle() const;
    void ColorPaddle(Color color);
    void MovePaddle(int deltaX, int deltaY);
    void SetPaddlePosition(int x, int y);
    void Reset();

    int GetX() const { return posX_; }
    int GetY() const { return posY_; }
    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }

private:
    int startX_;
    int startY_;
    int posX_;
    int posY_;
    int width_;
    int height_;
    Color color_;
};
