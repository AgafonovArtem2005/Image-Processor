#include "bmpformat.h"

void BMPFormat::SetFileSize(std::size_t file_size) {
    file_size_ = file_size;
}

void BMPFormat::SetOffsetPixelArray(std::size_t offset_pixel_array) {
    offset_pixel_array_ = offset_pixel_array;
}

void BMPFormat::SetImageSize(int32_t width, int32_t height) {
    width_ = width;
    height_ = height;
    CalculateRowSize();
}

void BMPFormat::SetWidth(int32_t width) {
    SetImageSize(width, height_);
}

void BMPFormat::SetHeight(int32_t height) {
    SetImageSize(width_, height);
}

void BMPFormat::SetBitmapSize(std::size_t bitmap_size) {
    bitmap_size_ = bitmap_size;
}

void BMPFormat::SetHorizontalResolution(int32_t horizontal_resolution) {
    horizontal_resolution_ = horizontal_resolution;
}

void BMPFormat::SetVerticalResolution(int32_t vertical_resolution) {
    vertical_resolution_ = vertical_resolution;
}

void BMPFormat::SetNumberOfColors(uint32_t number_of_colors) {
    number_of_colors_ = number_of_colors;
}

void BMPFormat::SetNumberOfImportantColors(uint32_t number_of_important_colors) {
    number_of_important_colors_ = number_of_important_colors;
}

void BMPFormat::CalculateRowSize() {
    row_size_ = (NUMBER_OF_BITS_PER_PIXEL * std::abs(width_) + ROW_OFFSET - 1) / ROW_OFFSET * 4;
}

void BMPFormat::CalculateBitmapSize() {
    CalculateRowSize();
    bitmap_size_ = row_size_ * std::abs(height_);
}

void BMPFormat::CalculateFileStructure() {
    CalculateBitmapSize();
    offset_pixel_array_ = OFFSET_PIXEL_ARRAY;
    file_size_ = offset_pixel_array_ + bitmap_size_;
}

std::size_t BMPFormat::GetFileSize() const {
    return file_size_;
}

std::size_t BMPFormat::GetOffsetPixelArray() const {
    return offset_pixel_array_;
}

int32_t BMPFormat::GetWidth() const {
    return width_;
}

int32_t BMPFormat::GetHeight() const {
    return height_;
}

std::size_t BMPFormat::GetBitmapSize() const {
    return bitmap_size_;
}

int32_t BMPFormat::GetHorizontalResolution() const {
    return horizontal_resolution_;
}

int32_t BMPFormat::GetVerticalResolution() const {
    return vertical_resolution_;
}

uint32_t BMPFormat::GetNumberOfColors() const {
    return number_of_colors_;
}

uint32_t BMPFormat::GetNumberOfImportantColors() const {
    return number_of_important_colors_;
}

std::size_t BMPFormat::GetRowSize() const {
    return row_size_;
}
