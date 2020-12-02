#pragma once

#include <concepts>

#include "Integer.hpp"

using Natural = Integer<unsigned int>;

template<typename T>
concept Group = requires(T a, T b) {
    { T{}}; /// T{} = 0
    { a + b } -> std::convertible_to<T>;
    { a - b } -> std::convertible_to<T>;
    { -a } -> std::convertible_to<T>;
};


template<typename T>
concept Ring = Group<T> && requires(T a, T b) {
    { T::one() } -> std::convertible_to<T>;
    { a * b } -> std::convertible_to<T>;
};


template<typename T>
concept EuclideanRing = Ring<T> && requires(T a, T b) {
    { euc(a) } -> std::convertible_to<Natural>;
    { a % b } -> std::convertible_to<T>;
};

template<typename T>
concept Field = Group<T> && requires(T a, T b) {
    { a / b } -> std::convertible_to<T>;
    { reverse(a) } -> std::convertible_to<T>;
};
