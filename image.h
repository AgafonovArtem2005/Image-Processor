#pragma once

#include "color.h"

class Image {
public:
    Image() = default;

    void SetSize(std::size_t height, std::size_t width);
    void SetHeight(std::size_t height);
    void SetWidth(std::size_t width);
    void SetPixel(std::size_t row, std::size_t col, Color pixel);

    std::size_t GetHeight() const;
    std::size_t GetWidth() const;
    Color GetPixel(ssize_t row, ssize_t col) const;

    void FlipHorizontally();
    void FlipVertically();

private:
    std::size_t height_;
    std::size_t width_;
    std::vector<std::vector<Color>> pixels_;

    void Resize();
};
