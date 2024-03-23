#include "filtergrayscale.h"

Color FilterGrayscale::Calculate(const Color &pixel) const {
    uint8_t saturation = static_cast<uint8_t>(RED_COEFFICIENT * pixel.GetRed() + GREEN_COEFFICIENT * pixel.GetGreen() +
                                              BLUE_COEFFICIENT * pixel.GetBlue());
    return Color(saturation, saturation, saturation);
}
