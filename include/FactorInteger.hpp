#pragma once

#include "Algebra.hpp"

template<unsigned int mod, std::integral T = unsigned int>
struct FactorInteger {
    /// Не простым модулям проход воспрещён

    constexpr FactorInteger() : value{0} {}

    constexpr FactorInteger(T value) : value{value % m_mod} {}

    constexpr static FactorInteger one() {
        return 1;
    }

    constexpr FactorInteger operator+(FactorInteger other) const {
        return (value + other.value) % m_mod;
    }

    constexpr FactorInteger operator-(FactorInteger other) const {
        return (value - other.value + m_mod) % m_mod;
    }

    constexpr FactorInteger operator-() const {
        return m_mod - value;
    }

    constexpr FactorInteger operator*(FactorInteger other) const {
        return (value * other.value) % m_mod;
    }

    constexpr FactorInteger operator/(FactorInteger other) const {
        return this->operator*(reverse(other));
    }

    constexpr FactorInteger operator^(Natural pow) {
        return binary_pow(*this, pow);
    }

    friend constexpr FactorInteger reverse(FactorInteger other) {
        return other ^ Natural(m_mod - 2);
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
    static constexpr T m_mod = mod;
};
