#include "filteredgedetection.h"

MatrixFilterEdgeDetection::MatrixFilterEdgeDetection() {
    matrix_.resize(3);
    for (std::size_t i = 0; i < 3; ++i) {
        matrix_[i].resize(3);
    }
    matrix_[0][0] = 0;
    matrix_[0][1] = -1;
    matrix_[0][2] = 0;
    matrix_[1][0] = -1;
    matrix_[1][1] = 4;
    matrix_[1][2] = -1;
    matrix_[2][0] = 0;
    matrix_[2][1] = -1;
    matrix_[2][2] = 0;
}

FilterEdgeDetection::FilterEdgeDetection(double threshold)
    : threshold_(static_cast<uint8_t>(threshold * COLOR_MAX_VALUE)) {
}

void FilterEdgeDetection::Apply(Image &image) const {
    FilterGrayscale filter_grayscale;
    MatrixFilterEdgeDetection matrix_filter_edge_detection;
    filter_grayscale.Apply(image);
    matrix_filter_edge_detection.Apply(image);
    for (std::size_t i = 0; i < image.GetHeight(); ++i) {
        for (std::size_t j = 0; j < image.GetWidth(); ++j) {
            if (image.GetPixel(static_cast<ssize_t>(i), static_cast<ssize_t>(j)).GetRed() > threshold_) {
                image.SetPixel(i, j, WHITE);
            } else {
                image.SetPixel(i, j, BLACK);
            }
        }
    }
}
