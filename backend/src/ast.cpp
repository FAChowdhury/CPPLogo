#include "ast.h"

namespace ast {
    AST::AST(std::vector<std::unique_ptr<ast::ASTNode>> &&ast)
    : ast_(std::move(ast)) {}

    auto AST::run(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) -> void {
        int count = 0;
        for (const auto &node : ast_) {
            node->execute(turtle, image, memory);
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
    auto PenUpNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.set_pen_up();
        return std::monostate{};
    }

    void PenUpNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Pen Up" << std::endl;
        std::cout << "}," << std::endl;
    }

    // PENDOWNNODE
    auto PenDownNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.set_pen_down();
        return std::monostate{};
    }

    void PenDownNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Pen Down" << std::endl;
        std::cout << "}," << std::endl;
    }

    // FORWARDNODE
    ForwardNode::ForwardNode(int distance) 
    : distance_(distance) {}

    auto ForwardNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.go_forward(distance_, image);
        return std::monostate{};
    }

    void ForwardNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Forward(" << distance_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

    // BACKNODE
    BackNode::BackNode(int distance)
    : distance_(distance) {}

    auto BackNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.go_back(distance_, image);
        return std::monostate{};
    }

    void BackNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Back(" << distance_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }


    // LEFTNODE
    LeftNode::LeftNode(int distance)
    : distance_(distance) {};

    auto LeftNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.go_left(distance_, image);
        return std::monostate{};
    }

    void LeftNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Left(" << distance_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

    // RIGHTNODE
    RightNode::RightNode(int distance)
    : distance_(distance) {}

    auto RightNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.go_right(distance_, image);
        return std::monostate{};
    }

    void RightNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Right(" << distance_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

    // SETPENCOLORNODE
    SetPenColorNode::SetPenColorNode(graphics::Colour &colour)
    : colour_(colour) {}

    auto SetPenColorNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.set_pen_colour(colour_);
        return std::monostate{};
    }

    void SetPenColorNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  SetPenColour(" << static_cast<int>(colour_.r) << ", " << static_cast<int>(colour_.g) << ", " << static_cast<int>(colour_.b) << ", " << static_cast<int>(colour_.a) << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

    // TURNNODE
    TurnNode::TurnNode(int degrees) 
    : degrees_(degrees) {}

    auto TurnNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.turn(degrees_);
        return std::monostate{};
    }

    void TurnNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  Turn(" << degrees_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

    // SETHEADINGNODE
    SetHeadingNode::SetHeadingNode(int degrees) 
    : degrees_(degrees) {}

    auto SetHeadingNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.set_direction(degrees_);
        return std::monostate{};
    }

    void SetHeadingNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  SetHeading(" << degrees_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

    // SETXNODE
    SetXNode::SetXNode(int x)
    : x_(x) {}

    auto SetXNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.set_x(x_);
        return std::monostate{};
    }

    void SetXNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  SetX(" << x_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

    // SETYNODE
    SetYNode::SetYNode(int y)
    : y_(y) {}

    auto SetYNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.set_y(y_);
        return std::monostate{};
    }

    void SetYNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  SetY(" << y_ << ")" << std::endl;
        std::cout << "}," << std::endl;
    }

    // FILLNODE
    auto FillNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        turtle.fill(image);
        return std::monostate{};
    }

    void FillNode::debug() const {
        std::cout << "{" << std::endl;
        std::cout << "  FILL" << std::endl;
        std::cout << "}," << std::endl;
    }

    // MAKENODE
    MakeNode::MakeNode(std::unique_ptr<ASTNode> &&variable, std::unique_ptr<ASTNode> &&value)
    : variable_(std::move(variable))
    , value_(std::move(value)) {}

    auto MakeNode::execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const -> std::any {
        auto any_left = std::any(variable_->execute(turtle, image, memory));
        auto any_right = std::any(value_->execute(turtle, image, memory));
        auto left = std::optional<std::string>(std::nullopt);
        auto right = std::optional<std::string>(std::nullopt);

        try { // trying left
            // Attempt to cast to int
            auto intValue = std::any_cast<int>(any_left);
            left = std::to_string(intValue);
        } catch (const std::bad_any_cast&) {
            // If casting to int fails, attempt to cast to string
            try {
                auto left = std::any_cast<std::string>(any_left);
            } catch (const std::bad_any_cast&) {
                // If both casts fail, throw an exception
                throw std::runtime_error("Cannot cast std::any to either int or std::string"); // Need to figure out how to return logo error
            }
        }

        try { // trying right
            // Attempt to cast to int
            auto intValue = std::any_cast<int>(any_right);
            right = std::to_string(intValue);
        } catch (const std::bad_any_cast&) {
            // If casting to int fails, attempt to cast to string
            try {
                auto right = std::any_cast<std::string>(any_right);
            } catch (const std::bad_any_cast&) {
                // If both casts fail, throw an exception
                throw std::runtime_error("Cannot cast std::any to either int or std::string"); // Need to figure out how to return logo error
            }
        }

        if (left.has_value() and right.has_value()) {
            memory[left.value()] = right.value();
        }
        
        return std::monostate{};
    }

    auto MakeNode::debug() const -> void {
        std::cout << "{" << std::endl;
        std::cout << "  MAKE," << std::endl;
        std::cout << "  LEFT:" << std::endl;
        variable_->debug();
        std::cout << "  RIGHT:" << std::endl;
        value_->debug();
        std::cout << "}," << std::endl;
    }

    // XCORNODE

    // YCORNODE

    // HEADING

} // namespace ast