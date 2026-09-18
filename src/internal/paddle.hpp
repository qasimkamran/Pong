#pragma once

#include "raylib.h"

class Paddle
{
public:
    Paddle(float x, float y, float width, float height, Color color)
        : startX_(x), startY_(y), posX_(x), posY_(y),
          width_(width), height_(height), color_(color) {}

    void RenderPaddle() const;
    void ColorPaddle(Color color);
    void MovePaddle(float deltaX, float deltaY);
    void SetPaddlePosition(float x, float y);
    void Reset();

    float GetX() const { return posX_; }
    float GetY() const { return posY_; }
    float GetWidth() const { return width_; }
    float GetHeight() const { return height_; }
    Vector4 GetBoundingBox() const { return { posX_, posY_, posX_ + width_, posY_ + height_ }; }
private:
    float startX_;
    float startY_;

    float posX_;
    float posY_;

    float width_;
    float height_;

    Color color_;
};
