#pragma once

#include "utils.h"
#include "image.h"

namespace turtle {
    class Turtle {
     public:
        Turtle(const util::Dimension2D &dimensions);

        auto is_pen_down() const -> bool;
        auto set_x(int x) -> void;
        auto set_y(int y) -> void;
        auto set_position(int x, int y) -> void;
        auto turn(int degrees) -> void;
        auto set_direction(int degrees) -> void;
        auto set_pen_colour(const graphics::Colour &colour) -> void;
        auto set_pen_down() -> void;
        auto set_pen_up() -> void;

        auto go_forward(int distance, img::Image &image) -> void;
     private:
        util::Point2D position_;
        bool is_pen_down_;
        int direction_;
        graphics::Colour pen_colour_;
    };
} // namespace turtle