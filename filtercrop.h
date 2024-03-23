#pragma once

#include "filter.h"

class FilterCrop : public Filter {
public:
    FilterCrop() = default;
    FilterCrop(std::size_t height, std::size_t width);
    void Apply(Image& image) const override;

private:
    std::size_t height_;
    std::size_t width_;
};
