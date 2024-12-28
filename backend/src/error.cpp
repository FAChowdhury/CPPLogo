#include "error.h"

namespace error {
    LogoError::LogoError(ErrorType type, const std::string &msg, int line_num, int col_num)
    : type_(type)
    , msg_(msg)
    , line_number_(line_num)
    , column_number_(col_num) {}

    auto toString(ErrorType err) ->  std::string {
        switch (err) {
            case ErrorType::TOO_FEW_ARGUMENTS: {return "Too few arguments.";}
            case ErrorType::UNEXPECTED_TYPE: {return "Unexpected type.";}
            default: return "Unknown";
        }
    }
} // namespace error