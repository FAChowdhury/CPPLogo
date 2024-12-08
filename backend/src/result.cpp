#include "result.h"

namespace result {
    template<typename T, typename E>
    Result<T, E>::Result(const T &value, Status status)
    : value_(value)
    , status_(status) {}

    template<typename T, typename E>
    Result<T, E>::Result(const E &error, Status status)
    : value_(error)
    , status_(status) {}

    template<typename T, typename E>
    auto Result<T, E>::Ok(const T &value) -> Result<T, E> {
        return Result(value, Status::Ok);
    }

    template<typename T, typename E>
    auto Result<T, E>::Err(const E &error) -> Result<T, E> {
        return Result(error, Status::Err);
    }

    template<typename T, typename E>
    auto Result<T, E>::is_ok() const -> bool {
        return Status::Ok == status_;
    }

    template<typename T, typename E>
    auto Result<T, E>::is_err() const -> bool {
        return Status::Err == status_;
    }

    template<typename T, typename E>
    auto Result<T, E>::unwrap() const -> const T& {
        if (status_ == Status::Ok) {
            return std::get<T>(value_);
        }

        throw std::runtime_error("attempting to unwrap Ok() on Err value");
    }

    template<typename T, typename E>
    auto Result<T, E>::unwrap_err() const -> const E& {
        if (status_ == Status::Err) {
            return std::get<E>(value_);
        }

        throw std::runtime_error("attempting to unwrap Err() on Ok value");
    }

    template<typename T, typename E>
    auto Result<T, E>::unwrap() -> T& {
        if (status_ == Status::Ok) {
            return std::get<T>(value_);
        }

        throw std::runtime_error("attempting to unwrap Ok() on Err value");
    }

    template<typename T, typename E>
    auto Result<T, E>::unwrap_err() -> E& {
        if (status_ == Status::Err) {
            return std::get<E>(value_);
        }

        throw std::runtime_error("attempting to unwrap Err() on Ok value");
    }

} // result
