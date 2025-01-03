#include "main.h"

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
        // parse tokens into AST
        auto ast = parser.parse();
        if (ast.is_ok()) {
            ast.unwrap().run_debug();
            ast.unwrap().run(turtle, image);
            // save the image as png
            image.save_png(argv[2]);
        } else {
            logo_error::print_logo_error(ast.unwrap_err(), lines, argv[1]);
            return 1;
        }
    } else if (lines.is_err()) {
        std::cerr << lines.unwrap_err() << std::endl;
        return 1;
    }

    return 0;
}
