#pragma once

#include <vector>
#include <string>

#include "Algebra.hpp"


template<Field T>
class Polynomial {
public:
    Polynomial() : coefficients{} {}

    explicit Polynomial(std::vector<T> coefficients) : coefficients{std::move(coefficients)} {
        normalize();
    }

    static Polynomial one() {
        return Polynomial{{1}};
    }

    bool operator==(const Polynomial &other) const {
        return coefficients == other.coefficients;
    }

    Polynomial operator+(Polynomial other) const {
        if (other.coefficients.size() < coefficients.size()) {
            other.coefficients.resize(coefficients.size());
        }
        for (size_t i = 0; i < coefficients.size(); ++i) {
            other.coefficients[i] = other.coefficients[i] + coefficients[i];
        }
        other.normalize();
        return other;
    }

    Polynomial operator-(Polynomial other) const {
        if (other.coefficients.size() < coefficients.size()) {
            other.coefficients.resize(coefficients.size());
        }
        for (size_t i = 0; i < coefficients.size(); ++i) {
            other.coefficients[i] = coefficients[i] - other.coefficients[i];
        }
        for (size_t i = coefficients.size(); i < other.coefficients.size(); ++i) {
            other.coefficients[i] = -other.coefficients[i];
        }
        other.normalize();
        return other;
    }

    Polynomial operator-() const {
        std::vector<T> ans_coefficients;
        ans_coefficients.reserve(coefficients.size());
        for (const T &coefficient : coefficients) {
            ans_coefficients.push_back(-coefficient);
        }
        return Polynomial(ans_coefficients);
    }

    Polynomial operator*(const Polynomial &other) const {
        std::vector<T> product(other.coefficients.size() + coefficients.size());
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            for (size_t j = 0; j < coefficients.size(); ++j) {
                product[i + j] = product[i + j] + other.coefficients[i] * coefficients[j];
            }
        }
        return Polynomial(product);
    }

    Polynomial operator/(const Polynomial &other) const {
        if (coefficients.size() < other.coefficients.size()) {
            return {};
        }
        std::vector<T> coefficientsTMP = coefficients;
        std::vector<T> div(coefficients.size() - other.coefficients.size() + 1);
        for (size_t i = div.size() - 1; i != static_cast<size_t>(-1); --i) {
            div[i] = coefficientsTMP[other.coefficients.size() + i - 1] / other.coefficients.back();
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                coefficientsTMP[j + i] = coefficientsTMP[j + i] - div[i] * other.coefficients[j];
            }
        }
        return Polynomial(div);
    }

    Polynomial operator%(const Polynomial &other) const {
        if (coefficients.size() < other.coefficients.size()) {
            return *this;
        }
        std::vector<T> coefficientsTMP = coefficients;
        for (size_t i = coefficients.size() - other.coefficients.size(); i != static_cast<size_t>(-1); --i) {
            T k = coefficientsTMP[other.coefficients.size() + i - 1] / other.coefficients.back();
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                coefficientsTMP[j + i] = coefficientsTMP[j + i] - k * other.coefficients[j];
            }
        }
        return Polynomial(coefficientsTMP);
    }

    Polynomial operator*(T scalar) const {
        std::vector<T> ans(coefficients.size());
        for (size_t i = 0; i < coefficients.size(); ++i) {
            ans[i] = coefficients[i] * scalar;
        }
        return Polynomial(ans);
    }

    friend Polynomial operator*(T scalar, Polynomial other) {
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            other.coefficients[i] = other.coefficients[i] * scalar;
        }
        return other;
    }

    Polynomial operator^(Natural pow) {
        return binary_pow(*this, pow);
    }

    friend Natural euc(const Polynomial &poly) {
        return static_cast<unsigned int>(poly.pow() + 1);
    }

    [[nodiscard]] size_t pow() const {
        return coefficients.size() - 1;
    }

    T operator[](size_t index) const {
        return coefficients[index];
    }

    [[nodiscard]] std::string view() const {
        std::string out;
        bool first = true;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            if (coefficients[i] != T{}) {
                if (!first) {
                    out.push_back('+');
                    out.push_back(' ');
                } else {
                    first = false;
                }
                if (i == 0 || coefficients[i] != T::one()) {
                    out.append(coefficients[i].view());
                }
                if (i > 0) {
                    out.push_back('x');
                    if (i > 1) {
                        out.push_back('^');
                        out.append(std::to_string(i));
                    }
                }
                out.push_back(' ');
            }
        }
        out.pop_back();
        return out;
    }

private:
    void normalize() {
        while (!coefficients.empty() && coefficients.back() == T{}) {
            coefficients.pop_back();
        }
    }

    std::vector<T> coefficients;
};
