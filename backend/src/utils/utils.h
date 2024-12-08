#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdint>
#include "result.h"

using Lines = std::vector<std::vector<std::string>>;
using Error = std::string;

namespace graphics {
    struct Colour {
        // Todo: add another constructor so people can pass a value from a colour enum like colour::BLUE
        Colour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
        uint8_t r, g, b, a;
    };
} // namespace graphics

namespace util {
    struct Dimension2D {
        Dimension2D(unsigned int width, unsigned int height);
        unsigned int w;
        unsigned int h;
    };

    struct Point2D {
        Point2D(int x, int y);
        int x;
        int y;
    };
} // namespace util

namespace file {
    auto txt_file_to_lines(const std::string &file_path) -> result::Result<Lines, std::string>;
} // namespace file
