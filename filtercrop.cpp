#include "filtercrop.h"

FilterCrop::FilterCrop(std::size_t height, std::size_t width) {
    height_ = height;
    width_ = width;
}

void FilterCrop::Apply(Image &image) const {
    image.FlipHorizontally();
    image.SetHeight(std::min(image.GetHeight(), height_));
    image.FlipHorizontally();
    image.SetWidth(std::min(image.GetWidth(), width_));
}
