#include <gtest/gtest.h>

#include "simple_csv.hpp"

void check(const char *csv) {
    simple_csv::reader<> reader(csv);

    int expected = 1;

    for (auto row: reader) {
        for (auto col: row) {
            int value;

            EXPECT_TRUE(col.get(value));
            EXPECT_EQ(expected++, value);
        }
    }
}

TEST(Integer, Valid) {
    const char csv[] = "1,2,3\n4,5,6\n7,8,9";
    check(csv);
}

TEST(Integer, ValidTrailingNewline) {
    const char csv[] = "1,2,3\n4,5,6\n7,8,9\n";
    check(csv);
}

TEST(Integer, ValidDoubleNewlines) {
    const char csv[] = "1,2,3\n\n4,5,6\n\n7,8,9";
    check(csv);
}

TEST(Integer, ValidDoubleNewlinesDoubleTrailingNewlines) {
    const char csv[] = "1,2,3\n\n4,5,6\n\n7,8,9\n\n";
    check(csv);
}
