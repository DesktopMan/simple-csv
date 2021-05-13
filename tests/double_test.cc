#include <gtest/gtest.h>

#include "util.hpp"

TEST(Double, Valid) {
    check<double>(
            "-5.7,0.0,3.4",
            {-5.7, 0.0, 3.4}
    );
}

TEST(Double, EndOfInput) {
    check<double>(
            "",
            {0.0},
            result::END_OF_INPUT
    );
}

TEST(Double, UnexpectedDelimiter) {
    check<double>(
            ",",
            {0.0},
            result::UNEXPECTED_DELIMITER
    );
}

TEST(Double, UnexpectedQuote) {
    check<double>(
            "\"",
            {0.0},
            result::UNEXPECTED_QUOTE
    );
}

TEST(Double, UnexpectedNewline) {
    check<double>(
            "\n",
            {0.0},
            result::UNEXPECTED_NEWLINE
    );
}

TEST(Double, UnexpectedData) {
    check<double>(
            "123.456abc",
            {0,9},
            result::UNEXPECTED_DATA
    );
}
