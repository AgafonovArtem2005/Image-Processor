#include "pixelfilter.h"

void PixelFilter::Apply(Image &image) const {
    for (std::size_t row = 0; row < image.GetHeight(); ++row) {
        for (std::size_t col = 0; col < image.GetWidth(); ++col) {
            image.SetPixel(row, col, Calculate(image.GetPixel(static_cast<ssize_t>(row), static_cast<ssize_t>(col))));
        }
    }
}
