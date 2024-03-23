#include "bmpreader.h"

void BMPReader::OpenFile(const std::string& file_path) {
    file_.open(file_path, std::ios::binary);
    if (!file_.is_open()) {
        throw std::runtime_error("Input file doesn't exists!");
    }
    number_of_byte_ = 0;
}

void BMPReader::CloseFile() {
    file_.close();
}

uint8_t BMPReader::GetByte() {
    uint8_t info = 0;
    if (!file_.read(reinterpret_cast<char*>(&info), 1)) {
        throw std::runtime_error("Input file is corrupted!");
    }
    ++number_of_byte_;
    return info;
}

std::vector<uint8_t> BMPReader::GetBytes(std::size_t number_of_bytes) {
    std::vector<uint8_t> result(number_of_bytes);
    for (std::size_t i = 0; i < number_of_bytes; ++i) {
        result[i] = GetByte();
    }
    return result;
}

int16_t BMPReader::GetI16() {
    std::vector<uint8_t> buffer = GetBytes(2);
    int32_t result = 0;
    for (std::size_t i = 0; i < 2; ++i) {
        result |= static_cast<int32_t>(buffer[i]) << (NUMBER_OF_BITS_IN_INT8_T * i);
    }
    return static_cast<int16_t>(result);
}

int32_t BMPReader::GetI32() {
    std::vector<uint8_t> buffer = GetBytes(4);
    int32_t result = 0;
    for (std::size_t i = 0; i < 4; ++i) {
        result |= static_cast<int32_t>(buffer[i]) << (NUMBER_OF_BITS_IN_INT8_T * i);
    }
    return result;
}

Color BMPReader::GetColor() {
    Color result;
    result.SetBlue(GetByte());
    result.SetGreen(GetByte());
    result.SetRed(GetByte());
    return result;
}

Image BMPReader::GetImageFromFile(const std::string& file_path) {
    OpenFile(file_path);
    std::vector<uint8_t> buffer;
    buffer = GetBytes(2);  // ID field
    if (buffer[0] != ID_FIELD[0] || buffer[1] != ID_FIELD[1]) {
        throw std::runtime_error("Wrong input file format");
    }
    bmp_info_.SetFileSize(GetI32());          // Size of BMP
    GetBytes(4);                              // Application specific bytes
    bmp_info_.SetOffsetPixelArray(GetI32());  // Offset of bitmap image data
    std::size_t size_of_header = GetI32();    // Size of header
    if (size_of_header != DIB_SIZE) {
        throw std::runtime_error("Wrong input file format");
    }
    bmp_info_.SetWidth(GetI32());          // Width of bitmap
    bmp_info_.SetHeight(GetI32());         // Height of bitmap
    uint16_t number_of_planes = GetI16();  // Number of color planes
    if (number_of_planes != 1) {
        throw std::runtime_error("Wrong input file format");
    }
    uint16_t number_of_bits_per_pixel = GetI16();  // Number of bits per pixel
    if (number_of_bits_per_pixel != NUMBER_OF_BITS_PER_PIXEL) {
        throw std::runtime_error("Wrong input file format");
    }
    uint32_t compression_method = GetI32();  // Compression method
    if (compression_method != COMPRESSION_METHOD) {
        throw std::runtime_error("Wrong input file format");
    }
    bmp_info_.SetBitmapSize(GetI32());               // Size of Bitmap
    bmp_info_.SetHorizontalResolution(GetI32());     // Horizontal resolution
    bmp_info_.SetVerticalResolution(GetI32());       // Vertical resolution
    bmp_info_.SetNumberOfColors(GetI32());           // Number of colors in the color palette
    bmp_info_.SetNumberOfImportantColors(GetI32());  // Number of important colors used
    Image result;
    result.SetSize(bmp_info_.GetHeight(), bmp_info_.GetWidth());
    for (std::size_t row = 0; row < result.GetHeight(); ++row) {
        GetBytes(bmp_info_.GetOffsetPixelArray() + bmp_info_.GetRowSize() * row - number_of_byte_);  // Skip padding
        for (std::size_t col = 0; col < result.GetWidth(); ++col) {
            result.SetPixel(row, col, GetColor());
        }
    }
    if (bmp_info_.GetHeight() < 0) {
        result.FlipHorizontally();
    }
    if (bmp_info_.GetWidth() < 0) {
        result.FlipVertically();
    }
    CloseFile();
    return result;
}

BMPFormat BMPReader::GetBMPInfo() const {
    return bmp_info_;
}
