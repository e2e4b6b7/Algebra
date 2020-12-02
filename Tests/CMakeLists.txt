cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -fsanitize=address -fsanitize=undefined")

find_package(GTest REQUIRED)

add_executable(AlgebraTest testAll.cpp)

include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(AlgebraTest ${GTEST_LIBRARIES})

add_Test(Test AlgebraTest)
