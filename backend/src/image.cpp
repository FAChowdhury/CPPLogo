#include "image.h"

namespace img {
    Image::Image(unsigned int w, unsigned int h)
    : width_(w) 
    , height_(h)
    , image_(width_ * height_ * 4, 0) {
        // the image is black by default
        for (unsigned i = 0; i < width_ * height_; ++i) {
            image_[i * 4 + 3] = 255;
        }
    }

    auto Image::set_pixel(int x, int y, const graphics::Colour &colour) -> void {
        if (x >= 0 && x < width_ && y >= 0) { // Check if the pixel is within the image bounds
                int idx = (y * width_ + x) * 4;
                image_[idx] = colour.r;      // Red channel
                image_[idx + 1] = colour.g;  // Green channel
                image_[idx + 2] = colour.b;  // Blue channel
                image_[idx + 3] = colour.a;  // Alpha channel
        }
    }

    auto Image::draw_line(int x0, int y0, int angle, int length, const graphics::Colour &colour) ->  util::Point2D {
        // Convert angle from degrees to radians
        double rad = ((angle - 90.0) * M_PI) / 180.0;

        // Calculate the end point (x1, y1) based on length and angle
        int x1 = static_cast<int>(x0 + length * cos(rad));
        int y1 = static_cast<int>(y0 + length * sin(rad));

        // Calculate differences
        int dx = abs(x1 - x0);
        int dy = abs(y1 - y0);
        int sx = (x0 < x1) ? 1 : -1;
        int sy = (y0 < y1) ? 1 : -1;
        int err = dx - dy;

        while (true) {
            set_pixel(x0, y0, colour);

            if (x0 == x1 && y0 == y1) {return {x1, y1};}

            int e2 = err * 2;
            if (e2 > -dy) {
                err -= dy;
                x0 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y0 += sy;
            }
        }
    }

    auto Image::get_dimensions() -> util::Dimension2D {
        return {width_, height_};
    }

    auto Image::save_png(const std::string &name) -> void {
        unsigned error = lodepng::encode(name + ".png", image_, width_, height_);

        if (error) {
            std::cerr << "Error encoding PNG: " << lodepng_error_text(error) << std::endl;
        } else {    
            std::cout << "Image saved as " + name + ".png" << std::endl;
        }

        return;
    }
} // namespace img