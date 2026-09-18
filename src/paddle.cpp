#include "internal/paddle.hpp"

void Paddle::RenderPaddle() const
{
    DrawRectangle(posX_, posY_, width_, height_, color_);
}

void Paddle::ColorPaddle(Color color)
{
    color_ = color;
}

void Paddle::MovePaddle(int deltaX, int deltaY)
{
    SetPaddlePosition(posX_ + deltaX, posY_ + deltaY);
}

void Paddle::SetPaddlePosition(int x, int y)
{
    posX_ = x;
    posY_ = y;
}

void Paddle::Reset()
{
    SetPaddlePosition(startX_, startY_);
}

