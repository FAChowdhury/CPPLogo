#pragma once
#include <cstdint>

namespace graphics {
    struct Colour {
        Colour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
        uint8_t r, g, b, a;
    };
}

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
}
