#include "parserargv.h"

void ParserArgv::Parse(int argc, char **argv, std::string &input_file_path, std::string &output_file_path,
                       std::vector<std::unique_ptr<Filter>> &filters) {
    if (argc < 3) {
        throw std::runtime_error("Wrong format!");
    }
    input_file_path = argv[1];
    output_file_path = argv[2];
    for (std::size_t i = 3; i < static_cast<std::size_t>(argc); ++i) {
        if (std::strcmp(argv[i], "-crop") == 0) {
            if (static_cast<std::size_t>(argc) <= i + 2) {
                throw std::runtime_error("Wrong format!");
            }
            std::size_t width = std::stoi(argv[i + 1]);
            std::size_t height = std::stoi(argv[i + 2]);
            filters.push_back(std::make_unique<FilterCrop>(height, width));
            i += 2;
        } else if (std::strcmp(argv[i], "-gs") == 0) {
            filters.push_back(std::make_unique<FilterGrayscale>());
        } else if (std::strcmp(argv[i], "-neg") == 0) {
            filters.push_back(std::make_unique<FilterNegative>());
        } else if (std::strcmp(argv[i], "-sharp") == 0) {
            filters.push_back(std::make_unique<FilterSharpening>());
        } else if (std::strcmp(argv[i], "-edge") == 0) {
            if (static_cast<std::size_t>(argc) <= i + 1) {
                throw std::runtime_error("Wrong format!");
            }
            double threshold = std::stod(argv[i + 1]);
            filters.push_back(std::make_unique<FilterEdgeDetection>(threshold));
            i += 1;
        } else if (std::strcmp(argv[i], "-blur") == 0) {
            if (static_cast<std::size_t>(argc) <= i + 1) {
                throw std::runtime_error("Wrong format!");
            }
            double sigma = std::stod(argv[i + 1]);
            filters.push_back(std::make_unique<FilterGaussianBlur>(sigma));
            i += 1;
        } else {
            throw std::runtime_error("Wrong format!");
        }
    }
}
