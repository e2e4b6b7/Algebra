cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -fsanitize=address -fsanitize=undefined")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(AlgebraTest
        testAll.cpp
        testInteger.cpp
        testFactorInteger.cpp
        testPolynomial.cpp
        testFactorPolynomial.cpp)

include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(AlgebraTest ${GTEST_LIBRARIES} Threads::Threads)

add_Test(Test AlgebraTest)
