#include "gtest/gtest.h"

#include "FactorInteger.hpp"
#include "Algebra.hpp"

TEST(factor_integer, multiplication) {
    FactorInteger<13> a{8};
    FactorInteger<13> b{9};
    FactorInteger<13> c{7};
    EXPECT_EQ(a * b, c);
    FactorInteger<997> a_{137};
    FactorInteger<997> b_{940};
    FactorInteger<997> c_{167};
    EXPECT_EQ(a_ * b_, c_);
}

TEST(factor_integer, reverse) {
    FactorInteger<13> a{8};
    EXPECT_EQ(a * reverse(a), decltype(a)::one());
    FactorInteger<997> b{137};
    EXPECT_EQ(b * reverse(b), decltype(b)::one());
    FactorInteger<997> c{940};
    EXPECT_EQ(c * reverse(c), decltype(c)::one());
    FactorInteger<7369> d{3940};
    EXPECT_EQ(d * reverse(d), decltype(d)::one());
}
