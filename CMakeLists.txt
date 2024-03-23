project(image-processor)

cmake_minimum_required(VERSION 3.8)

set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)

include(cmake/BuildFlags.cmake)

include_directories(util)

add_executable(
    image_processor
    image_processor.cpp
        color.h
        color.cpp
        image.cpp
        image.h
        bmpformat.cpp
        bmpformat.h
        bmpreader.cpp
        bmpreader.h
        bmpwriter.cpp
        bmpwriter.h
        filter.cpp
        filter.h
        filtercrop.cpp
        filtercrop.h
        consoleoutput.cpp
        consoleoutput.h
        parserargv.cpp
        parserargv.h
        pixelfilter.cpp
        pixelfilter.h
        filtergrayscale.cpp
        filtergrayscale.h
        filternegative.cpp
        filternegative.h
        matrixfilter.cpp
        matrixfilter.h
        filtersharpening.cpp
        filtersharpening.h
        filteredgedetection.cpp
        filteredgedetection.h
        filtergaussianblur.cpp
        filtergaussianblur.h
)
