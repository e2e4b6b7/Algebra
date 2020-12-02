#pragma once

#include <concepts>

#include "AlgebraicDefines.hpp"

template<Field T>
constexpr T binary_pow(T value, Natural pow) {
    T ans = 1;
    std::integral auto pow_ = pow.value();
    decltype(pow_) ppow = 1u;
    while (ppow <= pow_) {
        if (pow_ & ppow) {
            ans = ans * value;
        }
        value = value * value;
        ppow <<= 1u;
    }
    return ans;
}
