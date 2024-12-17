#pragma once
#include <variant>
#include <string>
#include <stdexcept>
#include <types.h>
#include <error.h>

namespace result {
    template<typename T, typename E>
    class Result {
     public:
        enum class Status {Ok, Err};

        static auto Ok(const T &value) -> Result<T, E> {
            return Result(value, Status::Ok);
        }

        static auto Ok(T &&value) -> Result<T, E> {
            return Result(std::move(value), Status::Ok);
        }

        static auto Err(const E &error) -> Result<T, E> {
            return Result(error, Status::Err);
        }


        static auto Err(E &&error) -> Result<T, E> {
            return Result(std::move(error), Status::Err);
        }

        auto is_ok() const -> bool {
            return Status::Ok == status_;
        }

        auto is_err() const -> bool {
            return Status::Err == status_;
        }

        auto unwrap() const -> const T& {
            if (status_ == Status::Ok) {
                return std::get<T>(value_);
            }

            throw std::runtime_error("attempting to unwrap Ok() on Err value");
        }

        auto unwrap() -> T& {
            if (status_ == Status::Ok) {
                return std::get<T>(value_);
            }

            throw std::runtime_error("attempting to unwrap Ok() on Err value");
        }

        auto unwrap_err() const -> const E& {
            if (status_ == Status::Err) {
                return std::get<E>(value_);
            }

            throw std::runtime_error("attempting to unwrap Err() on Ok value");
        }

        auto unwrap_err() -> E& {
            if (status_ == Status::Err) {
                return std::get<E>(value_);
            }

            throw std::runtime_error("attempting to unwrap Err() on Ok value");
        }
        
     private:
        Result(const T &value, Status status)
        : value_(value)
        , status_(status) {}

        Result(T &&value, Status status)
        : value_(std::move(value))
        , status_(status) {}

        Result(const E &error, Status status)
        : value_(error)
        , status_(status) {}

        Result(E &&error, Status status)
        : value_(std::move(error))
        , status_(status) {}

        std::variant<T, E> value_;
        Status status_;
    };
} // namespace result