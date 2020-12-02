cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")

find_package(benchmark REQUIRED)

add_executable(AlgebraBenchmark benchAll.cpp)

target_link_libraries(AlgebraBenchmark benchmark::benchmark)
