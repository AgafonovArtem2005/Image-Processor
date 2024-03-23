#include "image.h"

void Image::SetSize(std::size_t height, std::size_t width) {
    height_ = height;
    width_ = width;
    Resize();
}

void Image::SetHeight(std::size_t height) {
    SetSize(height, width_);
}

void Image::SetWidth(std::size_t width) {
    SetSize(height_, width);
}

void Image::SetPixel(std::size_t row, std::size_t col, Color pixel) {
    if (height_ <= row || width_ < col) {
        throw std::runtime_error("Wrong index");
    }
    pixels_[row][col] = pixel;
}

std::size_t Image::GetHeight() const {
    return height_;
}

std::size_t Image::GetWidth() const {
    return width_;
}

Color Image::GetPixel(ssize_t row, ssize_t col) const {
    if (height_ == 0 || width_ == 0) {
        throw std::runtime_error("Wrong index");
    }
    row = std::max(static_cast<ssize_t>(0), row);
    row = std::min(static_cast<ssize_t>(height_) - 1, row);
    col = std::max(static_cast<ssize_t>(0), col);
    col = std::min(static_cast<ssize_t>(width_) - 1, col);
    return pixels_[row][col];
}

void Image::Resize() {
    pixels_.resize(height_);
    for (std::size_t row = 0; row < height_; ++row) {
        pixels_[row].resize(width_);
    }
}

void Image::FlipHorizontally() {
    std::reverse(pixels_.begin(), pixels_.end());
}

void Image::FlipVertically() {
    for (std::size_t row = 0; row < height_; ++row) {
        std::reverse(pixels_[row].begin(), pixels_[row].end());
    }
}
