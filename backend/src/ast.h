#pragma once
#include <any>
#include <memory>
#include <unordered_map>
#include <variant>
#include <vector>
#include "turtle.h"
#include "image.h"

namespace ast {
    class ASTNode {
     public:
        virtual ~ASTNode() = default;
        virtual std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const = 0;
        virtual void debug() const = 0;
    };

    class PenUpNode : public ASTNode {
     public:
        PenUpNode() = default;
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
    };

    class PenDownNode : public ASTNode {
     public:
        PenDownNode() = default;
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
    };

    class ForwardNode : public ASTNode {
     public:
        ForwardNode(int distance);
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
     private:
        int distance_;
    };

    class BackNode : public ASTNode {
     public:
        BackNode(int distance);
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
     private:
        int distance_;
    };

    class LeftNode : public ASTNode {
     public: 
        LeftNode(int distance);
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
     private:
        int distance_;
    };

    class RightNode : public ASTNode {
     public:
        RightNode(int distance);
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
     private:
        int distance_;
    };

    class SetPenColorNode : public ASTNode {
     public:
        SetPenColorNode(graphics::Colour &colour);
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
     private:
        graphics::Colour colour_;
    };
    
    class TurnNode : public ASTNode {
	 public:
		TurnNode(int degrees);
		std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
	 private:
		int degrees_;
	};

    class SetHeadingNode : public ASTNode {
     public:
        SetHeadingNode(int degrees);
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
     private:
        int degrees_;
    };

    class SetXNode : public ASTNode {
     public:
        SetXNode(int x);
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
     private:
        int x_;
    };

    class SetYNode : public ASTNode {
     public:
        SetYNode(int y);
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
     private:
        int y_;
    };

    class FillNode : public ASTNode {
     public:
        FillNode() = default;
        std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
    };

	class MakeNode : public ASTNode {
	 public:
		MakeNode(std::unique_ptr<ASTNode> &&variable, std::unique_ptr<ASTNode> &&value);
		std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
	 private:
		std::unique_ptr<ASTNode> variable_;
		std::unique_ptr<ASTNode> value_;
	};

	class XCorNode : public ASTNode {
	 public:
		XCorNode() = default;
		std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
	};

	class YCorNode : public ASTNode {
	 public:
	 	YCorNode() = default;
		std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
	};

	class HeadingNode : public ASTNode {
		HeadingNode() = default;
		std::any execute(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) const override;
        void debug() const override;
	}; 
    
    class AST {
     public:
        AST(std::vector<std::unique_ptr<ASTNode>> &&ast);
        auto run(turtle::Turtle &turtle, img::Image &image, std::unordered_map<std::string, std::string> &memory) -> void;
        auto run_debug() -> void;
     private:
        std::vector<std::unique_ptr<ASTNode>> ast_;
    };
} // namespace ast