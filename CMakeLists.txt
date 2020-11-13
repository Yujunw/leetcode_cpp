cmake_minimum_required(VERSION 3.16)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(leetcode_cpp main.cpp)
add_executable(fibonaci others/fibonacci.cpp)
add_executable(leetcode322 leetcode/leetcode322.cpp)
add_executable(leetcode46 leetcode/leetcode46.cpp)
add_executable(leetcode51 leetcode/leetcode51.cpp)
add_executable(bfs others/bfs.cpp)
add_executable(leetcode111 leetcode/leetcode111.cpp)
add_executable(leetcode752 leetcode/leetcode752.cpp)