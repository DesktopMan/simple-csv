#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <string>
#include <typeinfo>

#include <gtest/gtest.h>

#include "scsv.hpp"

using namespace scsv;

template <typename T, char delimiter=',', char decimal_separator='.'>
void check(const char csv[], std::vector<T> data, int expected = result::OK) {
    reader<delimiter, decimal_separator> reader(csv);

    int pos = 0;

    for (auto row: reader) {
        for (auto column: row) {
            EXPECT_LT(pos, data.size());

            T value;

            EXPECT_EQ(column.get(value), expected);

            if (expected == result::OK) {
                if (typeid(T) == typeid(int))
                    EXPECT_EQ(value, data[pos++]);
                else
                    EXPECT_FLOAT_EQ(value, data[pos++]);
            }
        }
    }
}

template <char delimiter=',', char decimal_separator='.'>
void check(const char csv[], std::vector<std::string> data, int expected = result::OK) {
    reader<delimiter, decimal_separator> reader(csv);

    int pos = 0;

    for (auto row: reader) {
        for (auto column: row) {
            EXPECT_LT(pos, data.size());

            char value[10];

            EXPECT_EQ(column.get(value, sizeof(value)), expected);

            if (expected == result::OK) {
                EXPECT_EQ(std::string(value), data[pos++]);
            }
        }
    }
}

#endif
