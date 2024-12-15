#pragma once
#include <string>

namespace error {
    enum class ErrorType { // add more when required
        MISMATCHED_TYPE,
        DIVISION_BY_ZERO,
        TOO_MANY_ARGUMENTS,
    };
    class LogoError {
     public:
        friend std::ostream& operator<<(std::ostream& os, const LogoError& le);
     private:
        ErrorType type_;
        std::string path_;
        int line_number_;
        int column_number_;
    };
} // namespace error