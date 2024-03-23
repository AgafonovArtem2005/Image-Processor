#include "matrixfilter.h"

void MatrixFilter::Apply(Image &image) const {
    Image result;
    result.SetSize(image.GetHeight(), image.GetWidth());
    for (std::size_t row = 0; row < image.GetHeight(); ++row) {
        for (std::size_t col = 0; col < image.GetWidth(); ++col) {
            double red = 0;
            double green = 0;
            double blue = 0;
            ssize_t dx = static_cast<ssize_t>(matrix_.size() / 2);
            for (ssize_t i = -dx; i <= dx; ++i) {
                ssize_t dy = static_cast<ssize_t>(matrix_[i + dx].size() / 2);
                for (ssize_t j = -dy; j <= dy; ++j) {
                    Color pixel = image.GetPixel(static_cast<ssize_t>(row + i), static_cast<ssize_t>(col + j));
                    red += matrix_[i + dx][j + dy] * pixel.GetRed();
                    green += matrix_[i + dx][j + dy] * pixel.GetGreen();
                    blue += matrix_[i + dx][j + dy] * pixel.GetBlue();
                }
            }
            red = std::max(static_cast<double>(0), red);
            red = std::min(static_cast<double>(COLOR_MAX_VALUE), red);
            green = std::max(static_cast<double>(0), green);
            green = std::min(static_cast<double>(COLOR_MAX_VALUE), green);
            blue = std::max(static_cast<double>(0), blue);
            blue = std::min(static_cast<double>(COLOR_MAX_VALUE), blue);
            result.SetPixel(row, col,
                            Color(static_cast<uint8_t>(red), static_cast<uint8_t>(green), static_cast<uint8_t>(blue)));
        }
    }
    image = result;
}
