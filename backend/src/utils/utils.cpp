#include "utils.h"

namespace graphics {
    Colour::Colour(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255)
    : r(red) 
    , g(green)
    , b(blue)
    , a(alpha) {}

    auto Colour::operator==(const Colour& other) const -> bool {
        return r == other.r && g == other.g && b == other.b && a == other.a;
    }

    auto Colour::operator!=(const Colour& other) const -> bool {
        return !(*this == other);
    }
} // namespace graphics

namespace util {
    Dimension2D::Dimension2D(unsigned int width, unsigned int height)
    : w(width)
    , h(height) {}

    Point2D::Point2D(int x, int y)
    : x(x)
    , y(y) {}
} // namespace util

namespace file {
    auto txt_file_to_lines(const std::string &file_path) -> result::Result<Lines, Error> {
        // Open the file
        auto fp = std::string(file_path);
        auto file = std::ifstream(fp);
        
        if (!file.is_open()) {
            auto err = std::string("Error: Could not open the file") + fp + "\n";
            return result::Result<Lines, std::string>::Err(err);
        }

        auto lines = Lines();
        auto line = std::string();

        // Read the file line by line
        while (std::getline(file, line)) {
            std::vector<std::string> words;
            
            std::stringstream ss(line);
            std::string word;
            
            // Split the line by spaces and add each word to the words vector
            while (ss >> word) {
                words.push_back(word);
            }
            
            lines.push_back(words);
        }
    
        file.close();

        return result::Result<Lines, std::string>::Ok(lines);
    }
} // namespace file

namespace dbg {
    auto title(const std::string &title) -> void {
        std::cout << std::endl; 
        std::cout << title << std::endl;
        std::cout << "#####################" << std::endl;
        std::cout << std::endl; 
    }
} // namespace dbg

namespace math {
    auto positive_modulo(int a, int b) -> int {
        int remainder = a % b;
        if (remainder < 0) {
            remainder += b;
        }
        return remainder;
    }
}