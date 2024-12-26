#include "parse.h"

namespace parse {
    Parser::Parser(std::vector<token::Token> &tokens)
    : tokens_(tokens) {}

    auto Parser::parse() -> result::Result<ast::AST, error::LogoError> {
        auto ast = std::vector<std::unique_ptr<ast::ASTNode>>();
        // todo:
        // iterate over the tokens
        // depending on the type of token, we obtain the next few tokens and create an AST node.
        // append the AST node to the AST
        // return the final AST.
        // if we encounter an error at any point, return an error
        int i = 0;
        while (i < tokens_.size()) {
            if (tokens_[i].type == token::TokenType::PENUP) {
                ast.push_back(std::make_unique<ast::PenUpNode>());
                i += 1;
            } else if (tokens_[i].type == token::TokenType::PENDOWN) {
                ast.push_back(std::make_unique<ast::PenDownNode>());
                i += 1;
            } else if (tokens_[i].type == token::TokenType::FORWARD) {
                if (i + 1 < tokens_.size() and tokens_[i+1].type == token::TokenType::NUMBER) {
                    ast.push_back(std::make_unique<ast::ForwardNode>(std::stoi(tokens_[i+1].word)));
                    i += 2;
                } else {
                    std::cerr << "ERROR on the following line number: " << tokens_[i].line_number << " and word number: " << tokens_[i].column_number << std::endl; 
                    std::exit(1); // todo: Return LogoError!
                }
            } else if (tokens_[i].type == token::TokenType::BACK) {
                if (i + 1 < tokens_.size() and tokens_[i+1].type == token::TokenType::NUMBER) {
                    ast.push_back(std::make_unique<ast::BackNode>(std::stoi(tokens_[i+1].word)));
                    i += 2;
                } else {
                    std::cerr << "ERROR on the following line number: " << tokens_[i].line_number << " and word number: " << tokens_[i].column_number << std::endl; 
                    std::exit(1); // todo: Return LogoError!
                }
            } else if (tokens_[i].type == token::TokenType::LEFT) {
                if (i + 1 < tokens_.size() and tokens_[i+1].type == token::TokenType::NUMBER) {
                    ast.push_back(std::make_unique<ast::LeftNode>(std::stoi(tokens_[i+1].word)));
                    i += 2;
                } else {
                    std::cerr << "ERROR on the following line number: " << tokens_[i].line_number << " and word number: " << tokens_[i].column_number << std::endl; 
                    std::exit(1); // todo: Return LogoError!
                }
            } else if (tokens_[i].type == token::TokenType::RIGHT) {
                if (i + 1 < tokens_.size() and tokens_[i+1].type == token::TokenType::NUMBER) {
                    ast.push_back(std::make_unique<ast::RightNode>(std::stoi(tokens_[i+1].word)));
                    i += 2;
                } else {
                    std::cerr << "ERROR on the following line number: " << tokens_[i].line_number << " and word number: " << tokens_[i].column_number << std::endl; 
                    std::exit(1); // todo: Return LogoError!
                }
            } else {
                std::cerr << "Did not implement: " << tokens_[i] << " in Parser::parse() yet!" << std::endl; 
                std::exit(1); // todo: Return LogoError!
            }
        }
        return result::Result<ast::AST, error::LogoError>::Ok(ast::AST(std::move(ast)));
    }
} // namespace parse