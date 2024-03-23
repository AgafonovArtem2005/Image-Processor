#include "bmpwriter.h"

void BMPWriter::SetBMPFormat(const BMPFormat &bmp_info) {
    bmp_info_ = bmp_info;
}

void BMPWriter::OpenFile(const std::string &file_path) {
    file_.open(file_path, std::ios::binary);
    number_of_byte_ = 0;
}

void BMPWriter::CloseFile() {
    file_.close();
}

void BMPWriter::WriteByte(uint8_t x) {
    file_.write(reinterpret_cast<char *>(&x), 1);
    ++number_of_byte_;
}

void BMPWriter::WriteBytes(std::vector<uint8_t> bytes) {
    for (size_t i = 0; i < bytes.size(); ++i) {
        WriteByte(bytes[i]);
    }
}

void BMPWriter::WriteEmptyBytes(size_t counter) {
    for (size_t i = 0; i < counter; ++i) {
        WriteByte(0);
    }
}

void BMPWriter::WriteI16(int16_t x) {
    std::vector<uint8_t> buffer(2);
    for (size_t i = 0; i < 2; ++i) {
        buffer[i] = (x >> (NUMBER_OF_BITS_IN_INT8_T * i)) & ((1 << NUMBER_OF_BITS_IN_INT8_T) - 1);
    }
    WriteBytes(buffer);
}

void BMPWriter::WriteI32(int32_t x) {
    std::vector<uint8_t> buffer(4);
    for (size_t i = 0; i < 4; ++i) {
        buffer[i] = (x >> (NUMBER_OF_BITS_IN_INT8_T * i)) & ((1 << NUMBER_OF_BITS_IN_INT8_T) - 1);
    }
    WriteBytes(buffer);
}

void BMPWriter::WriteColor(Color color) {
    WriteByte(color.GetBlue());
    WriteByte(color.GetGreen());
    WriteByte(color.GetRed());
}

void BMPWriter::WriteImageToFile(const std::string &file_name, const Image &image) {
    OpenFile(file_name);
    bmp_info_.SetImageSize(static_cast<int32_t>(image.GetWidth()), static_cast<int32_t>(image.GetHeight()));
    bmp_info_.CalculateFileStructure();
    WriteBytes({ID_FIELD[0], ID_FIELD[1]});                                  // ID field
    WriteI32(static_cast<int32_t>(bmp_info_.GetFileSize()));                 // Size of BMP
    WriteEmptyBytes(4);                                                      // Application specific bytes
    WriteI32(static_cast<int32_t>(bmp_info_.GetOffsetPixelArray()));         // Offset of bitmap image data
    WriteI32(DIB_SIZE);                                                      // Size of header
    WriteI32(bmp_info_.GetWidth());                                          // Width of bitmap
    WriteI32(bmp_info_.GetHeight());                                         // Height of bitmap
    WriteI16(1);                                                             // Number of color planes
    WriteI16(NUMBER_OF_BITS_PER_PIXEL);                                      // Number of bits per pixel
    WriteI32(COMPRESSION_METHOD);                                            // Compression method
    WriteI32(static_cast<int32_t>(bmp_info_.GetBitmapSize()));               // Size of Bitmap
    WriteI32(bmp_info_.GetHorizontalResolution());                           // Horizontal resolution
    WriteI32(bmp_info_.GetVerticalResolution());                             // Vertical resolution
    WriteI32(static_cast<int32_t>(bmp_info_.GetNumberOfColors()));           // Number of colors in the color palette
    WriteI32(static_cast<int32_t>(bmp_info_.GetNumberOfImportantColors()));  // Number of important colors used
    for (std::size_t row = 0; row < image.GetHeight(); ++row) {
        WriteEmptyBytes(bmp_info_.GetOffsetPixelArray() + bmp_info_.GetRowSize() * row - number_of_byte_);
        for (std::size_t col = 0; col < image.GetWidth(); ++col) {
            WriteColor(image.GetPixel(static_cast<ssize_t>(row), static_cast<ssize_t>(col)));
        }
    }
    WriteEmptyBytes(bmp_info_.GetFileSize() - number_of_byte_);
    CloseFile();
}
