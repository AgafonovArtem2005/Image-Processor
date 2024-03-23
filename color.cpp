#include "color.h"

Color::Color(uint8_t red, uint8_t green, uint8_t blue) : red_(red), green_(green), blue_(blue) {
}

Color::Color(uint8_t saturation) : Color(saturation, saturation, saturation) {
}

void Color::Set(uint8_t red, uint8_t green, uint8_t blue) {
    red_ = red;
    green_ = green;
    blue_ = blue;
}

void Color::SetRed(uint8_t red) {
    Set(red, green_, blue_);
}

void Color::SetGreen(uint8_t green) {
    Set(red_, green, blue_);
}

void Color::SetBlue(uint8_t blue) {
    Set(red_, green_, blue);
}

uint8_t Color::GetRed() const {
    return red_;
}

uint8_t Color::GetGreen() const {
    return green_;
}

uint8_t Color::GetBlue() const {
    return blue_;
}

Color Color::operator-() const {
    return Color(COLOR_MAX_VALUE - red_, COLOR_MAX_VALUE - green_, COLOR_MAX_VALUE - blue_);
}

bool Color::operator==(const Color &other) const {
    return red_ == other.red_ && green_ == other.green_ && blue_ == other.blue_;
}
