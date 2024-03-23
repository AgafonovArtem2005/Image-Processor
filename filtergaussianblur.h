#pragma once

#include "matrixfilter.h"

#include <cmath>

const uint32_t GAUSS_CONST = 6;

class MatrixFilterGaussianBlur : public MatrixFilter {
public:
    MatrixFilterGaussianBlur() = default;
    MatrixFilterGaussianBlur(double sigma, bool vertical);

private:
    double sigma_;

    double Calculate(ssize_t dx) const;
};

class FilterGaussianBlur : public Filter {
public:
    FilterGaussianBlur() = default;
    explicit FilterGaussianBlur(double sigma);

    void Apply(Image& image) const override;

private:
    double sigma_;
    MatrixFilterGaussianBlur horizontal_filter_;
    MatrixFilterGaussianBlur vertical_filter_;
};
