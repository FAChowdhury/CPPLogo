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
        if (x >= 0 and x < width_ and y >= 0 and y < height_) { // Check if the pixel is within the image bounds
                int idx = (y * width_ + x) * 4;
                image_[idx] = colour.r;      // Red channel
                image_[idx + 1] = colour.g;  // Green channel
                image_[idx + 2] = colour.b;  // Blue channel
                image_[idx + 3] = colour.a;  // Alpha channel
        }
    }

    auto Image::get_pixel_colour(int x, int y) -> std::optional<graphics::Colour> {
        if (x >= 0 and x < width_ and y >= 0 and y < height_) {
            int idx = (y * width_ + x) * 4;
            return graphics::Colour(image_[idx], image_[idx + 1], image_[idx + 2], image_[idx + 3]);
        }

        return std::nullopt;
    }

    auto Image::draw_line(int x0, int y0, int angle, int length, const graphics::Colour &colour) ->  util::Point2D {
        if (length < 0) {
            length = abs(length);
            angle += 180;
        }
        angle = math::positive_modulo(angle, 360);
        std::cout << "drawing line from: (" << x0 << ", " << y0 << ")" << std::endl;
        // Convert angle from degrees to radians
        double rad = ((angle - 90.0) * M_PI) / 180.0;

        // Calculate the end point (x1, y1) based on length and angle
        int x1 = static_cast<int>(x0 + length * cos(rad));
        int y1 = static_cast<int>(y0 + length * sin(rad));
        std::cout << "drawing line to: (" << x1 << ", " << y1 << ")" << std::endl;

        // Calculate differences
        int dx = abs(x1 - x0);
        int dy = abs(y1 - y0);
        int sx = (x0 < x1) ? 1 : -1;
        int sy = (y0 < y1) ? 1 : -1;
        int err = dx - dy;

        // bresenham's line algorithm
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

    auto Image::get_end_coordinates(int x0, int y0, int angle, int length) -> util::Point2D {
        if (length < 0) {
            length = abs(length);
            angle += 180;
        }
        std::cout << "moving from: (" << x0 << ", " << y0 << ")" << std::endl;
        // Convert angle from degrees to radians
        double rad = ((angle - 90.0) * M_PI) / 180.0;

        // Calculate the end point (x1, y1) based on length and angle
        int x1 = static_cast<int>(x0 + length * cos(rad));
        int y1 = static_cast<int>(y0 + length * sin(rad));
        std::cout << "moving to: (" << x1 << ", " << y1 << ")" << std::endl;
        return {x1, y1};
    }

    auto Image::flood_fill(int x, int y, graphics::Colour &old_colour, graphics::Colour &new_colour) -> void {
        if (new_colour == old_colour) {
            return;
        }
        
        if (get_pixel_colour(x, y).has_value()) {
            if (get_pixel_colour(x, y).value() == old_colour) {
                set_pixel(x, y, new_colour);
                flood_fill(x+1,y, old_colour, new_colour);
                flood_fill(x,y+1,old_colour,new_colour);
                flood_fill(x-1,y,old_colour,new_colour);
                flood_fill(x,y-1,old_colour,new_colour);
            }
        }
    }

    auto Image::get_dimensions() -> util::Dimension2D {
        return {width_, height_};
    }

    auto Image::save_png(const std::string &path) -> std::optional<Error> {
        unsigned error = lodepng::encode(path, image_, width_, height_);
        auto opt = std::optional<Error>();
        if (error) {
            opt = std::string("Error encoding PNG: ") + lodepng_error_text(error) + "\n";
        }

        return opt;
    }
} // namespace img