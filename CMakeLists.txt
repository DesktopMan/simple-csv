cmake_minimum_required(VERSION 3.19)
project(simple_parsers)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

include_directories(simple_parsers, "include")

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        simple_csv_test
        tests/integer_test.cc
        tests/double_test.cc
        tests/string_test.cc
)
target_link_libraries(
        simple_csv_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(simple_csv_test)
