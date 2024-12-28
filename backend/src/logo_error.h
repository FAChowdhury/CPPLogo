#pragma once
#include <string>

#include "utils.h"
#include "result.h"

namespace logo_error {
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

    auto print_logo_error(LogoError error, result::Result<Lines, Error> lines, const std::string path) -> void;
} // namespace error