cmake_minimum_required(VERSION 3.14)
project(interleave)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(interleave main.cpp)