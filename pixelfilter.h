#pragma once

#include "filter.h"

class PixelFilter : public Filter {
public:
    void Apply(Image& image) const override;

private:
    virtual Color Calculate(const Color& pixel) const = 0;
};
