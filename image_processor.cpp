#include "bmpreader.h"
#include "bmpwriter.h"
#include "consoleoutput.h"
#include "image.h"
#include "parserargv.h"

#include <string>

int main(int argc, char** argv) {
    ConsoleOutput console_output;
    try {
        if (argc == 1) {
            console_output.PrintInfo();
        } else {
            ParserArgv parser;
            std::string input_file_path;
            std::string output_file_path;
            std::vector<std::unique_ptr<Filter>> filters;
            BMPReader reader;
            BMPWriter writer;
            parser.Parse(argc, argv, input_file_path, output_file_path, filters);
            Image image = reader.GetImageFromFile(input_file_path);
            for (std::size_t i = 0; i < filters.size(); ++i) {
                filters[i]->Apply(image);
            }
            writer.SetBMPFormat(reader.GetBMPInfo());
            writer.WriteImageToFile(output_file_path, image);
        }
    } catch (const std::exception& ex) {
        console_output.PrintError(ex);
    }
    return 0;
}
