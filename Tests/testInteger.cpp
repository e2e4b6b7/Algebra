#include "gtest/gtest.h"

#include "Integer.hpp"
#include "Algebra.hpp"

TEST(integer, gcd) {
    Integer<int> a(5);
    Integer<int> b(6);
    EXPECT_EQ(gcd(a, b), Integer<int>::one());
    Integer<int> c(2);
    EXPECT_EQ(gcd(c, b), c);
    Integer<int> d(24565432);
    Integer<int> e(435643);
    EXPECT_EQ(gcd(d, e), Integer<int>::one());
    Integer<int> f(24565440);
    Integer<int> g(343453480);
    Integer<int> h(40);
    EXPECT_EQ(gcd(f, g), h);
}

TEST(integer, bezout_ratio) {
    Integer<long> a(11);
    Integer<long> b(13);
    auto[c, d]  = bezout_ratio(a, b);
    Integer<long> ce(6);
    Integer<long> de(-5);
    EXPECT_EQ(c, ce);
    EXPECT_EQ(d, de);
    Integer<long> a_(24565440);
    Integer<long> b_(343453480);
    auto[c_, d_]  = bezout_ratio(a_, b_);
    Integer<long> ce_(-3616550);
    Integer<long> de_(258673);
    EXPECT_EQ(c_, ce_);
    EXPECT_EQ(d_, de_);
}