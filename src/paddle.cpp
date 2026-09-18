#include "internal/paddle.hpp"

#include <algorithm>

void Paddle::RenderPaddle() const
{
    DrawRectangleRec({posX_, posY_, width_, height_}, color_);
}

void Paddle::ColorPaddle(Color color)
{
    color_ = color;
}

void Paddle::MovePaddle(float deltaX, float deltaY)
{
    SetPaddlePosition(posX_ + deltaX, posY_ + deltaY);
}

void Paddle::SetPaddlePosition(float x, float y)
{
    const float maxX = std::max(0.0f, static_cast<float>(GetScreenWidth()) - width_);
    const float maxY = std::max(0.0f, static_cast<float>(GetScreenHeight()) - height_);

    posX_ = std::clamp(x, 0.0f, maxX);
    posY_ = std::clamp(y, 0.0f, maxY);
}

void Paddle::Reset()
{
    SetPaddlePosition(startX_, startY_);
}

