#include "utils.h"

namespace graphics {
    Colour::Colour(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255)
    : r(red) 
    , g(green)
    , b(blue)
    , a(alpha) {}
} // namespace graphics

namespace util {
    Dimension2D::Dimension2D(unsigned int width, unsigned int height)
    : w(width)
    , h(height) {}

    Point2D::Point2D(int x, int y)
    : x(x)
    , y(y) {}
} // namespace util