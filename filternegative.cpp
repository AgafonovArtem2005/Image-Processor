#include "filternegative.h"

Color FilterNegative::Calculate(const Color &pixel) const {
    return -pixel;
}
