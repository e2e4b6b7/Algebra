#include "gtest/gtest.h"

#include "Algebra.hpp"
#include "FactorPolynomial.hpp"
#include "FactorInteger.hpp"

TEST(factor_polynomial, multiplication) {
    using F = FactorInteger<13>;
    Polynomial<F> factor({1, 1, 0, 0, 1});
    auto base = FactorPolynomial<F>::make_base(factor, true);

    Polynomial<F> ap({1, 2, 3});
    FactorPolynomial<F> a{ap, base};

    Polynomial<F> bp({3, 2, 1});
    FactorPolynomial<F> b{bp, base};

    Polynomial<F> ansp({7, 1, 0, 12});
    FactorPolynomial<F> ans{ansp, base};

    EXPECT_EQ((a * a) * b, ans);

    Polynomial<F> ansp_({1, 12, 12, 12});
    FactorPolynomial<F> ans_{ansp_, base};

    EXPECT_EQ(a ^ 98, ans_);
}

TEST(factor_polynomial, reverse) {
    using F = FactorInteger<13>;
    Polynomial<F> factor({1, 1, 0, 0, 1});
    auto base = FactorPolynomial<F>::make_base(factor, true);

    Polynomial<F> ap({1, 2, 3});
    FactorPolynomial<F> a{ap, base};

    EXPECT_TRUE(reversible(a));
    EXPECT_EQ(a * reverse(a), a.one());

    Polynomial<F> bp({3, 2, 1});

    factor = ap * bp;
    base = FactorPolynomial<F>::make_base(factor, false);

    FactorPolynomial<F> a_{ap, base};
    FactorPolynomial<F> b_{bp, base};

    Polynomial<F> cp({1, 0, 1});
    FactorPolynomial<F> c{cp, base};

    EXPECT_FALSE(reversible(a_));
    EXPECT_FALSE(reversible(b_));
    EXPECT_TRUE(reversible(c));
}