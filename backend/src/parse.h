#pragma once
#include <vector>

#include "ast.h"
#include "error.h"
#include "result.h"
#include "token.h"

namespace parse {
    class Parser {
     public:
        Parser(const std::vector<token::Token> &tokens);

        auto parse() -> result::Result<ast::AST, error::LogoError>;
     private:
        std::vector<token::Token> &tokens_;
    };
} // namespace parse