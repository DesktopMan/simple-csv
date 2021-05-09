cmake_minimum_required(VERSION 3.19)
project(simple_parsers)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

include_directories(simple_parsers, "include")

add_executable(simple_parsers main.cpp)