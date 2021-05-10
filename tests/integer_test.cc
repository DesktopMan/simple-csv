#include <gtest/gtest.h>

#include "util.hpp"

TEST(Integer, Valid) {
    check<int>(
            "1,2,3\n4,5,6\n7,8,9",
            {1,2,3,4,5,6,7,8,9}
    );
}

TEST(Integer, ValidTrailingNewline) {
    check<int>(
            "1,2,3\n4,5,6\n7,8,9\n",
            {1,2,3,4,5,6,7,8,9}
    );
}

TEST(Integer, ValidDoubleNewlines) {
    check<int>(
            "1,2,3\n\n4,5,6\n\n7,8,9",
            {1,2,3,4,5,6,7,8,9}
    );
}

TEST(Integer, ValidDoubleNewlinesDoubleTrailingNewlines) {
    check<int>(
            "1,2,3\n\n4,5,6\n\n7,8,9\n\n",
            {1,2,3,4,5,6,7,8,9}
    );
}
