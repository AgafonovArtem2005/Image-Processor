#pragma once

#include "bmpformat.h"
#include "image.h"

#include <fstream>

class BMPWriter {
public:
    BMPWriter() = default;

    void WriteImageToFile(const std::string& file_name, const Image& image);
    void SetBMPFormat(const BMPFormat& bmp_info);

private:
    std::ofstream file_;
    std::size_t number_of_byte_;
    BMPFormat bmp_info_;

    void OpenFile(const std::string& file_path);
    void CloseFile();

    void WriteByte(uint8_t x);
    void WriteBytes(std::vector<uint8_t> bytes);
    void WriteEmptyBytes(std::size_t counter);
    void WriteI16(int16_t x);
    void WriteI32(int32_t x);
    void WriteColor(Color color);
};
