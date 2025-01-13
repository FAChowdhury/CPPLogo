#pragma once

#include <string>
#include <sstream>
#include "utils.h"

namespace token {
    enum class TokenType {
        PENUP, // 0
        PENDOWN, // 1
        FORWARD, // 2
        BACK, // 3
        LEFT, // 4
        RIGHT, // 5
        SETPENCOLOR, // 6
        TURN, // 7
        SETHEADING, // 8
        SETX, // 9
        SETY, // 10
        NUMBER, // 11
        FILL, // 12
        STRING, // 13
        VARIABLE, // 14
        XCOR, // 15
        YCOR, // 16
        HEADING, // 17
        MAKE, // 18
        INVALID // 19
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