#pragma once
#include <vector>

#include "ast.h"
#include "logo_error.h"
#include "result.h"
#include "token.h"

namespace parse {
    class Parser {
     public:
        Parser(std::vector<token::Token> &tokens);

        auto parse() -> result::Result<ast::AST, logo_error::LogoError>;
     private:
        std::vector<token::Token> &tokens_;
    };
} // namespace parse