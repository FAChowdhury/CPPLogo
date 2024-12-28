#include "logo_error.h"

namespace logo_error {
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

    auto print_logo_error(LogoError error, result::Result<Lines, Error> lines, const std::string path) -> void {
        // find the max num digits of line_number.
            auto max = math::count_digits(error.line_number_);
            // for line_numbers with digits less than max, add two spaces.
            if (error.line_number_ < lines.unwrap().size()) {
                max = math::count_digits(error.line_number_ + 1);
            }

            std::cerr << "\033[31mERROR\033[0m: " << toString(error.type_) << std::endl;
            std::cerr << "--> " << path << " on line " << error.line_number_ << std::endl;

            if (error.line_number_ - 2 > -1) {
                std::cerr << error.line_number_ - 1;
                if (math::count_digits(error.line_number_ - 1) < max) {
                    std::cerr << "  | ";
                } else {
                    std::cerr << " | ";
                }
                for (int i = 0; i < lines.unwrap()[error.line_number_ - 2].size(); ++i) {
                    std::cerr << lines.unwrap()[error.line_number_ - 2][i] << " ";
                }
                std::cerr << std::endl;
            }

            std::cerr << "\033[31m" << error.line_number_ <<  "\033[0m";
            if (math::count_digits(error.line_number_) < max) {
                std::cerr << "  | ";
            } else {
                std::cerr << " | ";
            }
            for (int i = 0; i < lines.unwrap()[error.line_number_ - 1].size(); ++i) {
                if (i == error.column_number_ - 1) {
                    std::cerr << "\033[31m";
                    std::cerr << lines.unwrap()[error.line_number_ - 1][i] << " ";
                    std::cerr << "\033[0m";
                } else {
                    std::cerr << lines.unwrap()[error.line_number_ - 1][i] << " ";
                }
            }
            std::cerr << std::endl;
            if (error.line_number_ < lines.unwrap().size()) {
                std::cerr << error.line_number_ + 1 << " | ";
                for (int i = 0; i < lines.unwrap()[error.line_number_].size(); ++i) {
                    std::cerr << lines.unwrap()[error.line_number_][i] << " ";
                }
            std::cerr << std::endl;
            }
            std::cerr << error.msg_ << std::endl;
    }
} // namespace error