#pragma once
#include <variant>
#include <string>
#include <stdexcept>
#include <types.h>

namespace result {
   template<typename T, typename E>
   class Result {
    public:
      enum class Status {Ok, Err};

      static auto Ok(const T &value) -> Result<T, E>;
      static auto Err(const E &error) -> Result<T, E>;

      auto is_ok() const -> bool;
      auto is_err() const -> bool;
      auto unwrap() const -> const T&;
      auto unwrap() -> T&;
      auto unwrap_err() const -> const E&;
      auto unwrap_err() -> E&;
    private:
      Result(const T &value, Status status);
      Result(const E &error, Status status);

      std::variant<T, E> value_;
      Status status_;
   };
} // namespace result