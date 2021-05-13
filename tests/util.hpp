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
            ASSERT_LT(pos, data.size());

            T value;

            ASSERT_EQ(column.get(value), expected);

            if (expected == result::OK) {
                if (typeid(T) == typeid(int))
                    ASSERT_EQ(value, data[pos++]);
                else
                    ASSERT_FLOAT_EQ(value, data[pos++]);
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
            ASSERT_LT(pos, data.size());

            char value[10];

            ASSERT_EQ(column.get(value, sizeof(value)), expected);

            if (expected == result::OK) {
                ASSERT_EQ(std::string(value), data[pos++]);
            }
        }
    }
}

#endif
