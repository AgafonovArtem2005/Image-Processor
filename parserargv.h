#pragma once

#include "filtercrop.h"
#include "filtergrayscale.h"
#include "filtergaussianblur.h"
#include "filteredgedetection.h"
#include "filternegative.h"
#include "filtersharpening.h"

#include <cstring>
#include <memory>
#include <string>
#include <vector>

class ParserArgv {
public:
    void Parse(int argc, char **argv, std::string &input_file_path, std::string &output_file_path,
               std::vector<std::unique_ptr<Filter>> &filters);

private:
};
