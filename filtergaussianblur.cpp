#include "filtergaussianblur.h"

double MatrixFilterGaussianBlur::Calculate(ssize_t dx) const {
    return std::exp(-std::pow(static_cast<double>(dx) / sigma_, 2) / 2) / std::sqrt(2 * M_PI) / sigma_;
}

MatrixFilterGaussianBlur::MatrixFilterGaussianBlur(double sigma, bool vertical) {
    sigma_ = sigma;
    ssize_t size = std::ceil(GAUSS_CONST * sigma_);
    if (size % 2 == 0) {
        ++size;
    }
    if (vertical) {
        matrix_.resize(size);
        for (ssize_t i = 0; i < size; ++i) {
            matrix_[i].resize(1);
            matrix_[i][0] = Calculate(size / 2 - i);
        }
    } else {
        matrix_.resize(1);
        matrix_[0].resize(size);
        for (ssize_t i = 0; i < size; ++i) {
            matrix_[0][i] = Calculate(size / 2 - i);
        }
    }
}

FilterGaussianBlur::FilterGaussianBlur(double sigma) {
    sigma_ = sigma;
    horizontal_filter_ = MatrixFilterGaussianBlur(sigma_, false);
    vertical_filter_ = MatrixFilterGaussianBlur(sigma_, true);
}

void FilterGaussianBlur::Apply(Image &image) const {
    horizontal_filter_.Apply(image);
    vertical_filter_.Apply(image);
}
