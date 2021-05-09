#include <cstdio>

#include <gtest/gtest.h>

#include "simple_csv.hpp"

static void check(const char *csv) {
    simple_csv::reader<> reader(csv);

    int expected = 1;

    for (auto row: reader) {
        for (auto col: row) {
            EXPECT_LT(expected, 10);

            char expected_string[10];
            sprintf(expected_string, "%d", expected++);

            char value[10];

            EXPECT_TRUE(col.get(value, sizeof(value)));
            EXPECT_STREQ(value, expected_string);
        }
    }
}

TEST(String, ValidUnquoted) {
    const char csv[] = "1,2,3\n4,5,6\n7,8,9";
    check(csv);
}

TEST(String, ValidUnquotedTrailingNewline) {
    const char csv[] = "1,2,3\n4,5,6\n7,8,9\n";
    check(csv);
}

TEST(String, ValidQuoted) {
    const char csv[] = "\"1\",\"2\",\"3\"\n\"4\",\"5\",\"6\"\n\"7\",\"8\",\"9\"";
    check(csv);
}

TEST(String, ValidQuotedTrailingNewline) {
    const char csv[] = "\"1\",\"2\",\"3\"\n\"4\",\"5\",\"6\"\n\"7\",\"8\",\"9\"\n";
    check(csv);
}

TEST(String, ValidMixedQuoting) {
    const char csv[] = "\"1\",2,\"3\"\n4,\"5\",6\n\"7\",\"8\",\"9\"";
    check(csv);
}
