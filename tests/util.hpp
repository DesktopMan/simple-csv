#include <string>

#include <gtest/gtest.h>

#include "simple_csv.hpp"

template <typename T, char delimiter=',', char decimal_separator='.'>
void check(const char csv[], std::vector<T> expected) {
    simple_csv::reader<delimiter, decimal_separator> reader(csv);

    int pos = 0;

    for (auto row: reader) {
        for (auto column: row) {
            EXPECT_LT(pos, expected.size());

            T value;

            EXPECT_TRUE(column.get(value));

            if (typeid(T) == typeid(int))
                EXPECT_EQ(value, expected[pos++]);
            else
                EXPECT_FLOAT_EQ(value, expected[pos++]);
        }
    }
}

template <char delimiter=',', char decimal_separator='.'>
void check(const char csv[], std::vector<std::string> expected) {
    simple_csv::reader<delimiter, decimal_separator> reader(csv);

    int pos = 0;

    for (auto row: reader) {
        for (auto column: row) {
            EXPECT_LT(pos, expected.size());

            char value[10];

            EXPECT_TRUE(column.get(value, sizeof(value)));
            EXPECT_EQ(std::string(value), expected[pos++]);
        }
    }
}
