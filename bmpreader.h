#pragma once

#include "bmpformat.h"
#include "image.h"

#include <fstream>

class BMPReader {
public:
    BMPReader() = default;

    Image GetImageFromFile(const std::string& file_path);
    BMPFormat GetBMPInfo() const;

private:
    std::ifstream file_;
    std::size_t number_of_byte_;
    BMPFormat bmp_info_;

    void OpenFile(const std::string& file_path);
    void CloseFile();

    uint8_t GetByte();
    std::vector<uint8_t> GetBytes(std::size_t number_of_bytes);
    int16_t GetI16();
    int32_t GetI32();
    Color GetColor();
};
