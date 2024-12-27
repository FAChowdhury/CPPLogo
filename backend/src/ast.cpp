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

    // BACKNODE
    BackNode::BackNode(int distance)
    : distance_(distance) {}

    void BackNode::execute(turtle::Turtle &turtle, img::Image &image) const {
        turtle.go_back(distance_, image);
    }

    void BackNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Back(" << distance_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }


    // LEFTNODE
    LeftNode::LeftNode(int distance)
    : distance_(distance) {};

    void LeftNode::execute(turtle::Turtle &turtle, img::Image &image) const {
        turtle.go_left(distance_, image);
    }

    void LeftNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Left(" << distance_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

    // RIGHTNODE
    RightNode::RightNode(int distance)
    : distance_(distance) {}

    void RightNode::execute(turtle::Turtle &turtle, img::Image &image) const {
        turtle.go_right(distance_, image);
    }

    void RightNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Right(" << distance_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

    // SETPENCOLORNODE
    SetPenColorNode::SetPenColorNode(graphics::Colour &colour)
    : colour_(colour) {}

    void SetPenColorNode::execute(turtle::Turtle &turtle, img::Image &image) const {
        turtle.set_pen_colour(colour_);
    }

    void SetPenColorNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  SetPenColour(" << static_cast<int>(colour_.r) << ", " << static_cast<int>(colour_.g) << ", " << static_cast<int>(colour_.b) << ", " << static_cast<int>(colour_.a) << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

     // TURNNODE
    TurnNode::TurnNode(int degrees) 
    : degrees_(degrees) {}

    void TurnNode::execute(turtle::Turtle &turtle, img::Image &image) const {
        turtle.turn(degrees_);
    }

    void TurnNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Turn(" << degrees_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }
} // namespace ast