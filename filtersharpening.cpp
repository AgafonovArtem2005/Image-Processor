#include "filtersharpening.h"

FilterSharpening::FilterSharpening() {
    matrix_.resize(3);
    for (std::size_t i = 0; i < 3; ++i) {
        matrix_[i].resize(3);
    }
    matrix_[0][0] = 0;
    matrix_[0][1] = -1;
    matrix_[0][2] = 0;
    matrix_[1][0] = -1;
    matrix_[1][1] = SHARPENING_CENTER;
    matrix_[1][2] = -1;
    matrix_[2][0] = 0;
    matrix_[2][1] = -1;
    matrix_[2][2] = 0;
}
