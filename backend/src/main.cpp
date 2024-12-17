#include "main.h"

int main(int argc, char *argv[]) {
    // ./CPPLogo <.txt logo file> <img output path> <width> <height>
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <.txt logo file> <img output path> <width> <height>" << std::endl;
        return 1;
    }

    // convert <.txt logo file> to Lines
    // used to grab lines for error handling
    const auto lines = file::txt_file_to_lines(argv[1]); 
    auto image = img::Image(std::stoul(argv[3]), std::stoul(argv[4]));
    auto turtle = turtle::Turtle(image.get_dimensions());

    std::cout << std::endl;
    std::cout << "Logo File" << std::endl;
    std::cout << "#####################" << std::endl;
    std::cout << std::endl;

    if (lines.is_ok()) {
        // print each line in <.txt logo file>
        for (const auto &line : lines.unwrap()) {
            for (const auto &word : line) {
                std::cout << word << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl; 
        std::cout << "Tokens" << std::endl;
        std::cout << "#####################" << std::endl;
        std::cout << std::endl; 

        auto tokenizer = token::Tokenizer(lines.unwrap());
        auto tokens = tokenizer.tokenize();
        for (const auto &token : tokens) {
            std::cout << token << std::endl;
        }

        std::cout << std::endl; 
        std::cout << "Abstract Syntax Tree" << std::endl;
        std::cout << "#####################" << std::endl;
        std::cout << std::endl; 

        // pass tokens into the parser
        auto parser = parse::Parser(tokens);
        auto ast = parser.parse();
        if (ast.is_ok()) {
            ast.unwrap().run_debug();
        } else {
            // std::cerr << ast.unwrap_err() << std::endl;
            std::cerr << "LOGO ERROR: TODO" << std::endl;
            return 1;
        }
        // parse the tokens into an AST


    } else if (lines.is_err()) {
        std::cerr << lines.unwrap_err() << std::endl;
        return 1;
    }

    return 0;
}
