#pragma once

#include <cstdint>
#include <cmath>
#include <iostream>
#include <vector>

#include "lodepng.h"
#include "utils.h"


namespace img {
    class Image {
     public:
        Image(unsigned int w, unsigned int h);

        auto draw_line(int x0, int y0, int angle, int length, const graphics::Colour &colour) -> util::Point2D;
        auto get_dimensions() -> util::Dimension2D;
        auto save_png(const std::string &name) -> void;

     private:
        auto set_pixel(int x, int y, const graphics::Colour &colour) -> void;

        unsigned int width_;
        unsigned int height_;
        std::vector<uint8_t> image_;
    };
} // namespace img
