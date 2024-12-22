#pragma once

#include <cstdint>
#include <cmath>
#include <iostream>
#include <optional>
#include <vector>

#include "lodepng.h"
#include "utils.h"

// Example:
// // create a blank black image
// auto image = img::Image(200, 200);

// // draw a square
// auto green = graphics::Colour(0, 255, 0, 255);
// auto end_point = image.draw_line(50, 50, 90, 100, green);
// end_point = image.draw_line(end_point.x, end_point.y, 180, 100, green);
// end_point = image.draw_line(end_point.x, end_point.y, 270, 100, green);
// end_point = image.draw_line(end_point.x, end_point.y, 0, 100, green);

// // save the image as png
// image.save_png("green square");

namespace img {
    class Image {
     public:
        Image(unsigned int w, unsigned int h);

        auto draw_line(int x0, int y0, int angle, int length, const graphics::Colour &colour) -> util::Point2D;
        auto get_end_coordinates(int x0, int y0, int angle, int length) -> util::Point2D;
        auto get_dimensions() -> util::Dimension2D;
        auto save_png(const std::string &path) -> std::optional<Error>;

     private:
        auto set_pixel(int x, int y, const graphics::Colour &colour) -> void;

        unsigned int width_;
        unsigned int height_;
        std::vector<uint8_t> image_;
    };
} // namespace img
