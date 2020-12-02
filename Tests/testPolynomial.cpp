#include "gtest/gtest.h"

#include "Algebra.hpp"
#include "Polynomial.hpp"
#include "FactorInteger.hpp"

TEST(polynomial, sum) {
    using Poly = Polynomial<FactorInteger<13>>;

    Poly a({12, 3, 1, 7});
    Poly b({10, 7, 8, 4, 1});
    Poly c({9, 10, 9, 11, 1});
    Poly d({2, 9, 6, 3, 12});
    Poly e({3, 6, 5, 9, 12});
    EXPECT_EQ(a + b, c);
    EXPECT_EQ(a - b, d);
    EXPECT_EQ(-b, e);
}

TEST(polynomial, multiplication) {
    using Poly = Polynomial<FactorInteger<13>>;

    Poly a({12, 3, 1});
    Poly b({10, 7, 11});
    Poly c({3, 10, 7, 1, 11});
    EXPECT_EQ(a * b, c);
}

TEST(polynomial, division) {
    using Poly = Polynomial<FactorInteger<13>>;

    Poly a({12, 3, 1, 7, 9, 2});
    Poly b({0, 0, 1});
    Poly c({1, 7, 9, 2});
    EXPECT_EQ(a / b, c);

    Poly a_({12, 3, 1, 7, 9, 2});
    Poly b_({10, 7, 11});
    Poly c_({4, 9, 5, 12});
    EXPECT_EQ(a_ / b_, c_);
}


TEST(polynomial, remainder) {
    using Poly = Polynomial<FactorInteger<13>>;

    Poly a({12, 3, 1, 7, 9, 2});
    Poly b({10, 7, 11});
    EXPECT_EQ((a / b) * b + (a % b), a);

    Poly a1({12, 3, 1, 7, 9, 2, 5, 6, 3, 5, 11, 8, 3, 1});
    Poly b1({10, 7, 11, 5, 6});
    EXPECT_EQ((a1 / b1) * b1 + (a1 % b1), a1);


    Poly a_({1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3});
    Poly b_({6, 8, 4, 5, 5});
    EXPECT_EQ((a_ / b_) * b_ + (a_ % b_), a_);
}


TEST(polynomial, gcd) {
    using Poly = Polynomial<FactorInteger<13>>;

    Poly a({12, 3, 1, 7, 9, 2});
    Poly b({10, 7, 11});
    Poly d = gcd(a, b);
    EXPECT_EQ(gcd(a, b).pow(), 0);

    Poly c({3, 2, 4});
    a = a * c;
    b = b * c;
    EXPECT_EQ((gcd(a, b) / c).pow(), 0);
}

TEST(polynomial, bezout_ratio) {
    using Poly = Polynomial<FactorInteger<13>>;

    Poly a({3, 1});
    Poly b({1, 1});
    auto[qa, qb] = bezout_ratio(a, b);
    EXPECT_EQ(gcd(a, b), qa * a + qb * b);

    Poly a_({12, 3, 1, 7, 9, 2});
    Poly b_({10, 7, 11});
    auto[qa_, qb_] = bezout_ratio(a_, b_);
    EXPECT_EQ(gcd(a_, b_), qa_ * a_ + qb_ * b_);
}