#include <vector>
#include <iostream>
#include <ctime>

#include "Integer.hpp"
#include "FactorInteger.hpp"
#include "Polynomial.hpp"
#include "FactorPolynomial.hpp"

void additions() {
    Polynomial<FactorInteger<long, 13>> p1{{2, 5, 4}};
    Polynomial<FactorInteger<long, 13>> p2{{4, 1, 8, 5}};
    for (int i = 0; i < 100; ++i) {
        p2 = p2 + p1;
    }
    std::cout << p2.view() << std::endl;
}

void gcd() {
    Polynomial<FactorInteger<long, 13>> p1{{2, 5, 4, 7, 2}};
    Polynomial<FactorInteger<long, 13>> p2{{4, 1, 8, 5}};
    for (int i = 0; i < 100; ++i) {
        p2 = p2 + p1;
        p2 = gcd(p2, p1);
    }
    std::cout << p2.view() << std::endl;
}

void bezout() {
    Polynomial<FactorInteger<long, 13>> p1{{2, 5, 4, 7, 2}};
    Polynomial<FactorInteger<long, 13>> p2{{4, 1, 8, 5}};
    for (int i = 0; i < 100; ++i) {
        p2 = p2 + p1;
        auto[p3, p4] = bezout_ratio(p2, p1);
        p2 = p3 + p4;
    }
    std::cout << p2.view() << std::endl;
}


void multiplications() {
    Polynomial<FactorInteger<long, 13>> p1{{2, 5, 4}};
    Polynomial<FactorInteger<long, 13>> p2{{4, 1, 8, 5}};
    for (int i = 0; i < 100; ++i) {
        p2 = p2 * p1;
    }
    std::cout << p2.view() << std::endl;
}

void additions_factor() {
    Polynomial<FactorInteger<long, 13>> fac{{2, 5, 4}};
    FactorPolynomial<FactorInteger<long, 13>>::FactorPolynomialBase base{fac, true};
    Polynomial<FactorInteger<long, 13>> p1{{2, 5, 4}};
    Polynomial<FactorInteger<long, 13>> p2{{4, 1, 8, 5}};
    FactorPolynomial<FactorInteger<long, 13>> fp1{p1, base};
    FactorPolynomial<FactorInteger<long, 13>> fp2{p2, base};
    for (int i = 0; i < 100; ++i) {
        fp2 = fp2 + fp1;
    }
}

void multiplications_factor() {
    Polynomial<FactorInteger<long, 13>> fac{{2, 5, 4}};
    FactorPolynomial<FactorInteger<long, 13>>::FactorPolynomialBase base{fac, true};
    Polynomial<FactorInteger<long, 13>> p1{{2, 5, 4}};
    Polynomial<FactorInteger<long, 13>> p2{{4, 1, 8, 5}};
    FactorPolynomial<FactorInteger<long, 13>> fp1{p1, base};
    FactorPolynomial<FactorInteger<long, 13>> fp2{p2, base};
    for (int i = 0; i < 100; ++i) {
        fp2 = fp2 * fp1;
    }
}


void reverse_factor() {
    Polynomial<FactorInteger<>> fac{{1, 1, 0, 1, 1, 0, 0, 0, 1}};
    FactorPolynomial<FactorInteger<>>::FactorPolynomialBase base{fac, true};
    Polynomial<FactorInteger<>> p1{{2, 5, 4}};
    Polynomial<FactorInteger<>> p2{{4, 1, 8, 5}};
    FactorPolynomial fp1{p1, base};
    FactorPolynomial fp2{p2, base};
    for (int i = 0; i < 100; ++i) {
        fp1 = fp2;
        fp2 = reverse(reverse(fp2));
        std::cout << (fp1 == fp2);
    }
    std::cout << '\n';
}


int main() {
    long time = clock();
    /*additions();
    std::cout << clock() - time << std::endl;
    time = clock();
    multiplications();
    std::cout << clock() - time << std::endl;
    time = clock();
    gcd();
    std::cout << clock() - time << std::endl;
    time = clock();
    additions_factor();
    std::cout << clock() - time << std::endl;
    time = clock();
    multiplications_factor();
    std::cout << clock() - time << std::endl;
    time = clock();*/
    reverse_factor();
    std::cout << clock() - time << std::endl;
    time = clock();
}