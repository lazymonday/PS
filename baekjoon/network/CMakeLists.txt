cmake_minimum_required(VERSION 3.15)
project(network)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(GCC_ENABLE_WARNING "-O1 -Wall -Werror -Wno-unused-result")

add_executable(network main.cpp)