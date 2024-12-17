#pragma once
#include <vector>
#include <memory>
#include "turtle.h"

namespace ast {
    class ASTNode {
     public:
        virtual ~ASTNode() = default;
        virtual void execute(turtle::Turtle &turtle) const = 0;
        virtual void debug() const = 0;
    };

    class PenUpNode : public ASTNode {
     public:
        PenUpNode() = default;
        void execute(turtle::Turtle &turtle) const override;
        void debug() const override;
    };

    class PenDownNode : public ASTNode {
     public:
        PenDownNode() = default;
        void execute(turtle::Turtle &turtle) const override;
        void debug() const override;
    };
    
    class AST {
     public:
        AST(std::vector<std::unique_ptr<ASTNode>> &&ast);
        auto run(turtle::Turtle &turtle) -> void;
        auto run_debug() -> void;
     private:
        std::vector<std::unique_ptr<ASTNode>> ast_;
    };
} // namespace ast