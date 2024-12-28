#pragma once
#include <string>

namespace error {
    enum class ErrorType {
        TOO_FEW_ARGUMENTS,
        UNEXPECTED_TYPE,
    };

    auto toString(ErrorType err) -> std::string;

    struct LogoError {
        LogoError(ErrorType type, const std::string &msg, int line_num, int col_num);
        ErrorType type_;
        const std::string msg_;
        int line_number_;
        int column_number_;
    };
} // namespace error