#ifndef ALGEBRA_FIELDFACTOR_HPP
#define ALGEBRA_FIELDFACTOR_HPP

#include "Algebra/AlgebraicDefines.hpp"

template<Field T> requires requires(T a, T b){
    { a % b } -> std::convertible_to<T>;
}
class FieldFactor {
public:
    FieldFactor() : value{T{} % mod} {}

    explicit FieldFactor(const T &value) : value{value % mod} {}

    FieldFactor operator+(const FieldFactor &other) {
        return (value + other.value) % mod;
    }

    FieldFactor operator-(const FieldFactor &other) {
        return (value - other.value) % mod;
    }

    FieldFactor operator*(const FieldFactor &other) {
        return (value * other.value) % mod;
    }

    FieldFactor operator/(const FieldFactor &other) {
        return (value / other.value) % mod;
    }

    const T value;
};


#endif //ALGEBRA_FIELDFACTOR_HPP
