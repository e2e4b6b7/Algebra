#pragma once

#include "Algebra/AlgebraicDefines.hpp"
#include "Algebra/AlgebraicUtils.hpp"

template<std::integral T = long long, T mod = 2>
struct FactorInteger {
    /// Не простым модулям проход воспрещён

    constexpr FactorInteger() : value{0} {}

    constexpr FactorInteger(T value) : value{value % mod} {}

    constexpr static FactorInteger one() {
        return 1;
    }

    constexpr FactorInteger operator+(FactorInteger other) const {
        return (value + other.value) % mod;
    }

    constexpr FactorInteger operator-(FactorInteger other) const {
        return (value - other.value + mod) % mod;
    }

    constexpr FactorInteger operator-() const {
        return mod - value;
    }

    constexpr FactorInteger operator*(FactorInteger other) const {
        return (value * other.value) % mod;
    }

    constexpr FactorInteger operator/(FactorInteger other) const {
        return this->operator*(reverse(other));
    }

    constexpr FactorInteger operator^(Natural pow) {
        return binary_pow(*this, pow);
    }

    friend constexpr FactorInteger reverse(FactorInteger other) {
        return other ^ Natural(mod - 2);
    }

    std::string view() const {
        return std::to_string(value);
    }

    bool operator!=(FactorInteger other) const {
        return value != other.value;
    }

    bool operator==(FactorInteger other) const {
        return value == other.value;
    }

private:
    T value;
};
