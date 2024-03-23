#pragma once

#include "filtergrayscale.h"
#include "matrixfilter.h"

class MatrixFilterEdgeDetection : public MatrixFilter {
public:
    MatrixFilterEdgeDetection();

private:
};

class FilterEdgeDetection : public Filter {
public:
    FilterEdgeDetection() = default;
    explicit FilterEdgeDetection(double threshold);

    void Apply(Image &image) const override;

private:
    uint8_t threshold_;
};
