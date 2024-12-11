#pragma once

#include <string>
#include <sstream>
#include "utils.h"

namespace token {
    enum class TokenType {
        PENUP,
        PENDOWN,
        FORWARD,
        BACK,
        LEFT,
        RIGHT,
        SETPENCOLOR,
        TURN,
        SETHEADING,
        SETX,
        SETY,
        NUMBER,
        INVALID,
    };

    struct Token {
        const TokenType type;
        const std::string word;
        const int line_number;
        const int column_number;

        Token(TokenType t, const std::string &w, int ln, int cn);

        friend std::ostream& operator<<(std::ostream& os, const Token& t);
    };

    class Tokenizer {
     public:
        Tokenizer(const Lines &lines);

        auto tokenize() -> std::vector<Token>;

     private:
        auto is_number(const std::string &str) const -> bool;

        const Lines &lines_;
    };

} // namespace token