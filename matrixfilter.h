#pragma once

#include "filter.h"

class MatrixFilter : public Filter {
public:
    void Apply(Image& image) const override;

protected:
    std::vector<std::vector<double>> matrix_;
};
