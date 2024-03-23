#include "consoleoutput.h"

void ConsoleOutput::PrintInfo() const {
    std::cout << "Image processor made by Agafonov Artem" << std::endl;
    std::cout
        << "./image_processor {path to input file} {path to output file} [-{name of filter 1} [parameter of filter 1] "
           "[parameter of filter 2] ...] [-{name of filter 2} [parameter of filter 1] [parameter of filter 2] ...] ..."
        << std::endl;
    std::cout << "Names of filter:" << std::endl;
    std::cout << "-crop width height: Crop" << std::endl;
    std::cout << "-gs: Grayscale" << std::endl;
    std::cout << "-neg: Negative" << std::endl;
    std::cout << "-sharp: Sharpening" << std::endl;
    std::cout << "-edge threshold: Edge Detection" << std::endl;
    std::cout << "-blur sigma: Gaussian Blur" << std::endl;
}

void ConsoleOutput::PrintError(const std::exception &ex) const {
    std::cout << "Something went wrong: " << ex.what() << std::endl;
    std::cout << "Contact developer for support!" << std::endl;
}
