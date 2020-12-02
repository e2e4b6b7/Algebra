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
        if (euc(a) == 0) return {T{}, T::one()};
        T div = b / a;
        T mod = b % a;
        auto[q, p] = bezout_ratio(a, mod);
        return {q - div * p, p};
    } else {
        if (euc(b) == 0) return {T::one(), T{}};
        T div = a / b;
        T mod = a % b;
        auto[q, p] = bezout_ratio(b, mod);
        return {p, q - div * p};
    }
}