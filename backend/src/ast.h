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

    class BackNode : public ASTNode {
     public:
        BackNode(int distance);
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
     private:
        int distance_;
    };

    class LeftNode : public ASTNode {
     public: 
        LeftNode(int distance);
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
     private:
        int distance_;
    };

    class RightNode : public ASTNode {
     public:
        RightNode(int distance);
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
     private:
        int distance_;
    };

    class SetPenColorNode : public ASTNode {
     public:
        SetPenColorNode(graphics::Colour &colour);
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
     private:
        graphics::Colour colour_;
    };
    
    class TurnNode : public ASTNode {
	 public:
		TurnNode(int degrees);
		void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
	 private:
		int degrees_;
	};

    class SetHeadingNode : public ASTNode {
     public:
        SetHeadingNode(int degrees);
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
     private:
        int degrees_;
    };

    class SetXNode : public ASTNode {
     public:
        SetXNode(int x);
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
     private:
        int x_;
    };

    class SetYNode : public ASTNode {
     public:
        SetYNode(int y);
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
     private:
        int y_;
    };

    class FillNode : public ASTNode {
     public:
        FillNode() = default;
        void execute(turtle::Turtle &turtle, img::Image &image) const override;
        void debug() const override;
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