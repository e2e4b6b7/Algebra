#pragma once

#include <tuple>

#include "AlgebraicDefines.hpp"

template<EuclideanRing T>
T gcd(T a, T b) {
    if (euc(a) < euc(b)) {
        std::swap(a, b);
    }
    while (euc(b) != 0) {
        std::swap(a, b);
        b = b % a;
    }
    return a;
}

template<EuclideanRing T>
std::tuple<T, T> bezout_ratio(T a, T b) {
    if (euc(a) < euc(b)) {
        std::swap(a, b);
    }
    if (euc(b) == 0) return {T::one(), T{}};
    T div = a / b;
    T mod = a % b;
    auto[q, p] = bezout_ratio(mod, a);
    return {-p, T::one() + mod * q};
}