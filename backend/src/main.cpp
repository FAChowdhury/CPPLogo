#include <iostream>
#include <vector>
#include "lodepng.h"
#include <cmath>

// Function to set the pixel in the image (private in image class)
void setPixel(std::vector<uint8_t>& image, int width, int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    if (x >= 0 && x < width && y >= 0) { // Check if the pixel is within the image bounds
        int idx = (y * width + x) * 4;
        image[idx] = r;      // Red channel
        image[idx + 1] = g;  // Green channel
        image[idx + 2] = b;  // Blue channel
        image[idx + 3] = a;  // Alpha channel
    }
}

// Bresenham's Line Drawing Algorithm (with floating-point inputs for the angle)  (public in image class)
std::pair<int, int> drawLine(std::vector<uint8_t>& image, int width, int height, int x0, int y0, double angle, int length, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
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
        setPixel(image, width, x0, y0, r, g, b, a);

        if (x0 == x1 && y0 == y1)
            return {x1, y1};

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

int main() {
    // Image dimensions
    unsigned width = 200;
    unsigned height = 200;

    // Create a vector to hold the image data (RGBA format)
    std::vector<uint8_t> image(width * height * 4, 0);  // Initialize to 0 (black color)

    // Set the alpha channel to 255 (fully opaque) for every pixel
    for (unsigned i = 0; i < width * height; ++i) {
        image[i * 4 + 3] = 255;  // Set alpha to 255 (fully opaque)
    }

    // Starting point (x, y), angle, length of the line, and color (RGBA)
    int x0 = 100, y0 = 100;
    double angle = 45;  // Angle in degrees
    int length = 50;
    uint8_t r = 0, g = 255, b = 0, a = 255; // Red color with full opacity

    // Draw the line
    auto end_points = drawLine(image, width, height, x0, y0, angle, length, r, g, b, a);
    std::cout << end_points.first << ", " << end_points.second << std::endl;

    end_points = drawLine(image, width, height, end_points.first, end_points.second, 180, length, r, g, b, a);
    std::cout << end_points.first << ", " << end_points.second << std::endl;

    std::cout << "Line drawn successfully!" << std::endl;

    // Encode the image into a PNG file (public fn save_png() in image class)
    unsigned error = lodepng::encode("output.png", image, width, height);

    if (error) {
        std::cerr << "Error encoding PNG: " << lodepng_error_text(error) << std::endl;
        return 1;
    }

    std::cout << "Image saved as black_image.png" << std::endl;
    return 0;
}
