#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "lodepng.h"
#include "image.h"
#include "utils.h"
#include "result.h"
#include "tokenizer.h"

int main(int argc, char *argv[]) {
    // ./CPPLogo <.txt logo file> <img output path> <width> <height>
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <.txt logo file> <img output path> <width> <height>" << std::endl;
        return 1;
    }

    // convert <.txt logo file> to Lines
    // used to grab lines for error handling
    const auto lines = file::txt_file_to_lines(argv[1]); 

    if (lines.is_ok()) {
        // print each line in <.txt logo file>
        for (const auto &line : lines.unwrap()) {
            for (const auto &word : line) {
                std::cout << word << " ";
            }
            std::cout << std::endl;
        }
        auto tokenizer = token::Tokenizer(lines.unwrap());
        auto tokens = tokenizer.tokenize();

        for (const auto &token : tokens) {
            std::cout << token << std::endl;
        }
    } else if (lines.is_err()) {
        std::cerr << lines.unwrap_err() << std::endl;
        return 1;
    }

    return 0;
}
