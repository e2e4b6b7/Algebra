#pragma once

#include <stdexcept>
#include <tuple>
#include <memory>

#include "Algebra.hpp"
#include "Polynomial.hpp"

template<Field T>
class FactorPolynomial {
public:
    struct FactorPolynomialBase;

private:
    using Poly = Polynomial<T>;
    using Base = FactorPolynomialBase;

public:
    struct FactorPolynomialBase {
        FactorPolynomialBase(Poly factor, bool factor_prime) :
                factor(std::move(factor)), factor_prime(factor_prime) {}

        bool operator==(const Base &other) const {
            return factor == other.factor;
        }

        const Poly factor;
        const bool factor_prime{};
    };

    static std::shared_ptr<const Base> make_base(Poly factor, bool factor_prime) {
        return std::make_shared<const Base>(std::move(factor), factor_prime);
    }

public:
    FactorPolynomial() : polynomial{} {}

    FactorPolynomial(Poly coefficients, std::shared_ptr<const Base> base) :
            polynomial{std::move(coefficients)}, base{base} {}

    FactorPolynomial(const FactorPolynomial &poly) = default;

    void operator=(const FactorPolynomial &poly) {
        base_check(poly);
        polynomial = poly.polynomial;
    }

    void operator=(FactorPolynomial &&poly) {
        base_check(poly);
        polynomial = std::move(poly.polynomial);
    }

    FactorPolynomial(FactorPolynomial &&poly) : polynomial(std::move(poly.polynomial)) {
        base_check(poly);
    }

    FactorPolynomial one() {
        return FactorPolynomial{Poly::one(), base};
    }

    FactorPolynomial operator+(FactorPolynomial other) const {
        base_check(other);
        return {other.polynomial + polynomial, base};
    }

    FactorPolynomial operator-(FactorPolynomial other) const {
        base_check(other);
        return {other.polynomial - polynomial, base};
    }

    FactorPolynomial operator-() const {
        return {-polynomial, base};
    }

    FactorPolynomial operator*(const FactorPolynomial &other) const {
        base_check(other);
        return {(other.polynomial * polynomial) % base->factor, base};
    }

    FactorPolynomial operator/(const FactorPolynomial &other) const {
        base_check(other);
        return {other.polynomial / polynomial, base};
    }

    FactorPolynomial operator%(const FactorPolynomial &other) const {
        base_check(other);
        return {other.polynomial % polynomial, base};
    }

    FactorPolynomial operator^(Natural pow) const {
        return binary_pow(*this, pow);
    }

    FactorPolynomial operator*(T scalar) const {
        return {polynomial * scalar, base};
    }

    bool operator==(FactorPolynomial other) const {
        base_check(other);
        return polynomial == other.polynomial;
    }

    friend FactorPolynomial operator*(T scalar, FactorPolynomial other) {
        return {other.polynomial * scalar, other.base};
    }

    friend bool reversible(FactorPolynomial poly) {
        if (poly.base->factor_prime) return true;
        return gcd(poly.polynomial, poly.base->factor).pow() == 0;
    }

    friend FactorPolynomial reverse(FactorPolynomial poly) {
        Poly gcd_v = gcd(poly.polynomial, poly.base->factor);
        if (gcd_v.pow() != 0) {
            throw std::invalid_argument{"Polynomial irreversible"};
        }
        return FactorPolynomial(std::get<0>(bezout_ratio(poly.polynomial, poly.base->factor)) * reverse(gcd_v[0]),
                                poly.base);
    }

    std::string view() {
        return polynomial.view();
    }

private:
    inline void base_check(const FactorPolynomial &other) const {
        if (!(base == other.base || *base == *other.base)) {
            throw std::invalid_argument{
                    "Arithmetic operations are allowed only for elements from one field"};
        }
    }

    Poly polynomial;
    std::shared_ptr<const Base> base;
};
