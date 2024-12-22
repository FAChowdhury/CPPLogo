#pragma once
#include <vector>
#include <memory>
#include "turtle.h"
#include "image.h"

namespace ast {
    class ASTNode {
     public:
        virtual ~ASTNode() = default;
        virtual void execute(turtle::Turtle &turtle, img::Image &image) const = 0;
        virtual void debug() const = 0;
    };

    class PenUpNode : public ASTNode {
     public:
        PenUpNode() = default;
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
    };

    class PenDownNode : public ASTNode {
     public:
        PenDownNode() = default;
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
    };

    class ForwardNode : public ASTNode {
     public:
        ForwardNode(int distance);
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
     private:
        int distance_;
    };
    
    class AST {
     public:
        AST(std::vector<std::unique_ptr<ASTNode>> &&ast);
        auto run(turtle::Turtle &turtle, img::Image &image) -> void;
        auto run_debug() -> void;
     private:
        std::vector<std::unique_ptr<ASTNode>> ast_;
    };
} // namespace ast