cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_COMPILER g++-10)

project(Algebra VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wduplicated-branches -Wduplicated-cond -Wfloat-equal -Wconversion")

include_directories(include/)

enable_testing()

add_subdirectory(Tests)
add_subdirectory(Benchmark)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")

add_executable(Algebra
        include/Polynomial.hpp
        include/Algebra/AlgebraicDefines.hpp
        include/Integer.hpp
        main.cpp
        include/Algebra/AlgebraicUtils.hpp
        include/FactorInteger.hpp
        include/FactorPolynomial.hpp
        include/Algebra/AlgebraicDefaults.hpp include/Algebra.hpp)