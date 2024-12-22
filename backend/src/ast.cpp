#include "ast.h"

namespace ast {
    AST::AST(std::vector<std::unique_ptr<ast::ASTNode>> &&ast)
    : ast_(std::move(ast)) {}

    auto AST::run(turtle::Turtle &turtle, img::Image &image) -> void {
        int count = 0;
        for (const auto &node : ast_) {
            node->execute(turtle, image);
        }
    }

    auto AST::run_debug() -> void {
        std::cout << "[" << std::endl;
        for (const auto &node : ast_) {
            node->debug();
        }
        std::cout << "]" << std::endl;
    }

    // PENUPNODE
    void PenUpNode::execute(turtle::Turtle &turtle, img::Image &image) const {
        turtle.set_pen_up();
    }

    void PenUpNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Pen Up" << std::endl;
        std::cout << "}," << std::endl;
    }

    // PENDOWNNODE
    void PenDownNode::execute(turtle::Turtle &turtle, img::Image &image) const {
        turtle.set_pen_down();
    }

    void PenDownNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Pen Down" << std::endl;
        std::cout << "}," << std::endl;
    }

    // FORWARDNODE
    ForwardNode::ForwardNode(int distance) 
    : distance_(distance) {}

    void ForwardNode::execute(turtle::Turtle &turtle, img::Image &image) const {
        turtle.go_forward(distance_, image);
    }

    void ForwardNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Forward(" << distance_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

} // namespace ast