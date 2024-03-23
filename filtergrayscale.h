#pragma once

#include "pixelfilter.h"

const double RED_COEFFICIENT = 0.299;
const double GREEN_COEFFICIENT = 0.587;
const double BLUE_COEFFICIENT = 0.114;

class FilterGrayscale : public PixelFilter {
public:
private:
    Color Calculate(const Color& pixel) const override;
};
