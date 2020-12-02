#pragma once

#include <concepts>

template<std::integral T = long long>
struct Integer {
    constexpr Integer() : m_value{0} {}

    constexpr Integer(T value) : m_value{value} {}

    constexpr static Integer one() {
        return 1;
    }

    constexpr Integer operator+(Integer other) const {
        return m_value + other.m_value;
    }

    constexpr Integer operator-(Integer other) const {
        return m_value - other.m_value;
    }

    constexpr Integer operator-() const {
        return -m_value;
    }

    constexpr Integer operator*(Integer other) const {
        return m_value * other.m_value;
    }

    constexpr Integer operator/(Integer other) const {
        return m_value / other.m_value;
    }

    constexpr bool operator<(Integer other) const {
        return m_value < other.m_value;
    }

    constexpr bool operator==(Integer other) const {
        return m_value == other.m_value;
    }

    constexpr Integer operator%(Integer other) const {
        return m_value % other.m_value;
    }

    constexpr T value() {
        return m_value;
    }

    friend constexpr Integer<unsigned int> euc(Integer other) {
        return static_cast<unsigned int>(other.m_value);
    }

private:
    T m_value;
};
