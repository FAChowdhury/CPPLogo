#include "turtle.h"

namespace turtle {
    Turtle::Turtle(const util::Dimension2D &dimensions) 
    : position_(util::Point2D(static_cast<int>(dimensions.w / 2), static_cast<int>(dimensions.h / 2))) // turtle starts at centre of image
    , is_pen_down_(false)
    , direction_(0) // turtle initially faces up
    , pen_colour_(graphics::Colour(255, 255, 255, 255)) {} // colour is initially white

    auto Turtle::is_pen_down() const -> bool {
        return is_pen_down_;
    }

    auto Turtle::set_x(int x) -> void {
        position_.x = x;
    }   

    auto Turtle::set_y(int y) -> void {
        position_.y = y;
    }

    auto Turtle::set_position(int x, int y) -> void {
        position_.x = x;
        position_.y = y;
    }

    auto Turtle::turn(int degrees) -> void {
        direction_ += degrees;
    }

    auto Turtle::set_direction(int degrees) -> void {
        direction_ = degrees;
    }

    auto Turtle::set_pen_colour(const graphics::Colour &colour) -> void {
        pen_colour_ = graphics::Colour(colour.r, colour.g, colour.b, colour.a);
    }

    auto Turtle::set_pen_down() -> void {
        is_pen_down_ = true;
    }

    auto Turtle::set_pen_up() -> void {
        is_pen_down_ = false;
    }

    auto Turtle::go_forward(int distance, img::Image &image) -> void {
        if (is_pen_down()) {
            position_ = image.draw_line(position_.x, position_.y, direction_, distance, pen_colour_);
        } else {
            position_ = image.get_end_coordinates(position_.x, position_.y, direction_, distance);
        }
    }

    auto Turtle::go_back(int distance, img::Image &image) -> void {
        Turtle::go_forward(-distance, image);
    }

    auto Turtle::go_left(int distance, img::Image &image) -> void {
        if (is_pen_down()) {
            position_ = image.draw_line(position_.x, position_.y, direction_ - 90, distance, pen_colour_);
        } else {
            position_ = image.get_end_coordinates(position_.x, position_.y, direction_ - 90, distance);
        }
    }

    auto Turtle::go_right(int distance, img::Image &image) -> void {
        Turtle::go_left(-distance, image);
    }

    auto Turtle::fill(img::Image &image) -> void {
        auto old_colour = image.get_pixel_colour(position_.x, position_.y);
        if (old_colour.has_value()) {
            image.flood_fill(position_.x, position_.y, old_colour.value(), pen_colour_);
        }
    }
} // namespace turtle