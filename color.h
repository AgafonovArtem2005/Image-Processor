#pragma once

#include <algorithm>
#include <cstdint>

const uint8_t COLOR_MAX_VALUE = 255;

class Color {
public:
    Color() = default;

    explicit Color(uint8_t saturation);
    Color(uint8_t red, uint8_t green, uint8_t blue);

    void Set(uint8_t red, uint8_t green, uint8_t blue);

    void SetRed(uint8_t red);
    void SetGreen(uint8_t green);
    void SetBlue(uint8_t blue);

    uint8_t GetRed() const;
    uint8_t GetGreen() const;
    uint8_t GetBlue() const;

    Color operator-() const;
    bool operator==(const Color& other) const;

private:
    uint8_t red_;
    uint8_t green_;
    uint8_t blue_;
};

const Color BLACK = Color(0);
const Color WHITE = Color(255);
