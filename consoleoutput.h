#pragma once

#include <exception>
#include <iostream>

class ConsoleOutput {
public:
    void PrintInfo() const;
    void PrintError(const std::exception& ex) const;

private:
};
