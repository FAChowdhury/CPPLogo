#pragma once
#include <vector>

namespace ast {
    class ASTNode {
     public:
        virtual ~ASTNode() = default;
        virtual void evaluate() const = 0;
    };
    
    class AST {
     public:
     private:
        std::vector<ASTNode> ast_;
    };
} // namespace ast