#include "token.h"

namespace token {
    // Token
    Token::Token(TokenType t, const std::string &w, int ln, int cn)
        : type(t)
        , word(w)
        , line_number(ln)
        , column_number(cn) {}

    std::ostream& operator<<(std::ostream& os, const Token& t) {
        // Output the x and y values of the Point
        os << "{" << "type: " << static_cast<int>(t.type) << ", word: " << t.word << ", ln: " << t.line_number << ", cn: " << t.column_number << "}";
        return os;  // Return the stream to allow chaining
    }

    // Tokenizer
    Tokenizer::Tokenizer(const Lines &lines)
    : lines_(lines) {}
    auto Tokenizer::tokenize() -> std::vector<Token> {
        auto tokens = std::vector<Token>();
        for (std::size_t row = 0; row < lines_.size(); ++row) {
            for (std::size_t col = 0; col < lines_[row].size(); ++col) {
                auto &word = lines_[row][col];

                if (word[0] == '/' and word[1] == '/') {break;} // skip the line because we hit a comment

                if (word[0] == '\"') { // number (add more later e.g. deref type for ':')
                    const auto var = lines_[row][col].substr(1);
                    if (is_number(var)) {
                        tokens.push_back(token::Token(token::TokenType::NUMBER, var, row + 1, col + 1));
                    } // add more as we think about MAKE assignments. (e.g. string type for '\"' thats not a number)
                } else { // command
                    if (word == "PENUP") {
                        tokens.push_back(token::Token(token::TokenType::PENUP, word, row + 1, col + 1));
                    } else if (word == "PENDOWN") {
                        tokens.push_back(token::Token(token::TokenType::PENDOWN, word, row + 1, col + 1));
                    } else if (word == "FORWARD") {
                        tokens.push_back(token::Token(token::TokenType::FORWARD, word, row + 1, col + 1));
                    } else if (word == "BACK") {
                        tokens.push_back(token::Token(token::TokenType::BACK, word, row + 1, col + 1));
                    } else if (word == "LEFT") {
                        tokens.push_back(token::Token(token::TokenType::LEFT, word, row + 1, col + 1));
                    } else if (word == "RIGHT") {
                        tokens.push_back(token::Token(token::TokenType::RIGHT, word, row + 1, col + 1));
                    } else if (word == "TURN") {
                        tokens.push_back(token::Token(token::TokenType::TURN, word, row + 1, col + 1));
                    } else if (word == "SETHEADING") {
                        tokens.push_back(token::Token(token::TokenType::SETHEADING, word, row + 1, col + 1));
                    } else if (word == "SETX") {
                        tokens.push_back(token::Token(token::TokenType::SETX, word, row + 1, col + 1));
                    } else if (word == "SETY") {
                        tokens.push_back(token::Token(token::TokenType::SETY, word, row + 1, col + 1));
                    } else if (word == "SETPENCOLOR") {
                        tokens.push_back(token::Token(token::TokenType::SETPENCOLOR, word, row + 1, col + 1));
                    } else {
                        tokens.push_back(token::Token(token::TokenType::INVALID, word, row + 1, col + 1));
                    }
                }
            }
        }

        return tokens;
    }

    auto Tokenizer::is_number(const std::string &str) const -> bool {
        try {
            std::stoi(str);
            return true;     
        } catch (...) {
            return false;
        }
    }
} // namespace token