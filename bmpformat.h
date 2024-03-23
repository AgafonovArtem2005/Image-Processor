#pragma once

#include <array>
#include <cmath>
#include <cstdint>

const uint8_t ID_FIELD[2] = {'B', 'M'};
const std::size_t DIB_SIZE = 40;
const uint16_t NUMBER_OF_BITS_PER_PIXEL = 24;
const uint32_t COMPRESSION_METHOD = 0;
const std::size_t NUMBER_OF_BITS_IN_INT8_T = 8;
const std::size_t ROW_OFFSET = 32;
const std::size_t OFFSET_PIXEL_ARRAY = 54;

class BMPFormat {
public:
    void SetFileSize(std::size_t file_size);
    void SetOffsetPixelArray(std::size_t offset_pixel_array);
    void SetImageSize(int32_t width, int32_t height);
    void SetWidth(int32_t width);
    void SetHeight(int32_t height);
    void SetBitmapSize(std::size_t bitmap_size);
    void SetHorizontalResolution(int32_t horizontal_resolution);
    void SetVerticalResolution(int32_t vertical_resolution);
    void SetNumberOfColors(uint32_t number_of_colors);
    void SetNumberOfImportantColors(uint32_t number_of_important_colors);

    std::size_t GetFileSize() const;
    std::size_t GetOffsetPixelArray() const;
    int32_t GetWidth() const;
    int32_t GetHeight() const;
    std::size_t GetBitmapSize() const;
    int32_t GetHorizontalResolution() const;
    int32_t GetVerticalResolution() const;
    uint32_t GetNumberOfColors() const;
    uint32_t GetNumberOfImportantColors() const;
    std::size_t GetRowSize() const;

    void CalculateFileStructure();

private:
    std::size_t file_size_;
    std::size_t offset_pixel_array_;
    int32_t width_;
    int32_t height_;
    std::size_t bitmap_size_;
    int32_t horizontal_resolution_;
    int32_t vertical_resolution_;
    uint32_t number_of_colors_;
    uint32_t number_of_important_colors_;
    std::size_t row_size_;

    void CalculateRowSize();
    void CalculateBitmapSize();
};
