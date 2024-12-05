#include <iostream>
#include <vector>
#include "lodepng.h"
#include <cmath>
#include "image.h"
#include "utils.h"

int main() {
    // create a blank black image
    auto image = img::Image(200, 200);

    // draw a square
    auto green = graphics::Colour(0, 255, 0, 255);
    auto end_point = image.draw_line(50, 50, 90, 100, green);
    end_point = image.draw_line(end_point.x, end_point.y, 180, 100, green);
    end_point = image.draw_line(end_point.x, end_point.y, 270, 100, green);
    end_point = image.draw_line(end_point.x, end_point.y, 0, 100, green);

    // save the image as png
    image.save_png("green square");
    return 0;
}
