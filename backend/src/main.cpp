#include "main.h"

int countDigits(int number) {
    // Handle the special case when the number is 0
    if (number == 0) {
        return 1;
    }
    
    // For negative numbers, work with their absolute value
    return static_cast<int>(floor(log10(abs(number)))) + 1;
}

int main(int argc, char *argv[]) {
    // ./CPPLogo <.txt logo file> <img output path> <width> <height>
    // ./CPPLogo ../logo/1_04_turn_rel.txt ../image/output.png 200 200
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <.txt logo file> <img output path> <width> <height>" << std::endl;
        return 1;
    }

    // convert <.txt logo file> to Lines
    // used to grab lines for error handling
    const auto lines = file::txt_file_to_lines(argv[1]); 
    auto image = img::Image(std::stoul(argv[3]), std::stoul(argv[4]));
    auto turtle = turtle::Turtle(image.get_dimensions());

    dbg::title("Logo File");

    if (lines.is_ok()) {
        // print each line in <.txt logo file>
        for (const auto &line : lines.unwrap()) {
            for (const auto &word : line) {
                std::cout << word << " ";
            }
            std::cout << std::endl;
        }

        dbg::title("Tokens");

        auto tokenizer = token::Tokenizer(lines.unwrap());
        auto tokens = tokenizer.tokenize();
        for (const auto &token : tokens) {
            std::cout << token << std::endl;
        }

        dbg::title("Abstract Syntax Tree");
        
        // pass tokens into the parser
        auto parser = parse::Parser(tokens);
        auto ast = parser.parse();
        if (ast.is_ok()) {
            ast.unwrap().run_debug();
            ast.unwrap().run(turtle, image);
            // save the image as png
            image.save_png(argv[2]);
        } else {
            // std::cerr << ast.unwrap_err() << std::endl;
            auto error = ast.unwrap_err();
            // std::cerr << "LOGO ERROR: TODO" << std::endl;
            // return 1;
            // Output the formatted error message

            // find the max num digits of line_number.
            auto max = countDigits(error.line_number_);
            // for line_numbers with digits less than max, add two spaces.
            if (error.line_number_ < lines.unwrap().size()) {
                max = countDigits(error.line_number_ + 1);
            }

            std::cerr << "\033[31mERROR\033[0m: " << error::toString(error.type_) << std::endl;
            std::cerr << "--> " << argv[1] << " on line " << error.line_number_ << std::endl;

            if (error.line_number_ - 2 > -1) {
                std::cerr << error.line_number_ - 1;
                if (countDigits(error.line_number_ - 1) < max) {
                    std::cerr << "  | ";
                } else {
                    std::cerr << " | ";
                }
                for (int i = 0; i < lines.unwrap()[error.line_number_ - 2].size(); ++i) {
                    std::cerr << lines.unwrap()[error.line_number_ - 2][i] << " ";
                }
                std::cerr << std::endl;
            }

            std::cerr << "\033[31m" << error.line_number_ <<  "\033[0m";
            if (countDigits(error.line_number_) < max) {
                std::cerr << "  | ";
            } else {
                std::cerr << " | ";
            }
            for (int i = 0; i < lines.unwrap()[error.line_number_ - 1].size(); ++i) {
                if (i == error.column_number_ - 1) {
                    std::cerr << "\033[31m";
                    std::cerr << lines.unwrap()[error.line_number_ - 1][i] << " ";
                    std::cerr << "\033[0m";
                } else {
                    std::cerr << lines.unwrap()[error.line_number_ - 1][i] << " ";
                }
            }
            std::cerr << std::endl;
            if (error.line_number_ < lines.unwrap().size()) {
                std::cerr << error.line_number_ + 1 << " | ";
                for (int i = 0; i < lines.unwrap()[error.line_number_].size(); ++i) {
                    std::cerr << lines.unwrap()[error.line_number_][i] << " ";
                }
            std::cerr << std::endl;
            }
            std::cerr << error.msg_ << std::endl;
        }
        // parse the tokens into an AST


    } else if (lines.is_err()) {
        std::cerr << lines.unwrap_err() << std::endl;
        return 1;
    }

    return 0;
}
