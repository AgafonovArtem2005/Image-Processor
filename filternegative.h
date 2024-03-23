#pragma once

#include "pixelfilter.h"

class FilterNegative : public PixelFilter {
public:
private:
    Color Calculate(const Color& pixel) const override;
};
