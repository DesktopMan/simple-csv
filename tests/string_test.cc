#include <gtest/gtest.h>

#include "util.hpp"


TEST(String, ValidUnquoted) {
    check(
            "1,2,3\n4,5,6\n7,8,9",
            {"1","2","3","4","5","6","7","8","9"}
    );
}

TEST(String, ValidUnquotedTrailingNewline) {
    check(
            "1,2,3\n4,5,6\n7,8,9\n",
            {"1","2","3","4","5","6","7","8","9"}
    );
}

TEST(String, ValidQuoted) {
    check(
            "\"1\",\"2\",\"3\"\n\"4\",\"5\",\"6\"\n\"7\",\"8\",\"9\"",
            {"1","2","3","4","5","6","7","8","9"}
    );
}

TEST(String, ValidQuotedTrailingNewline) {
    check(
            "\"1\",\"2\",\"3\"\n\"4\",\"5\",\"6\"\n\"7\",\"8\",\"9\"\n",
            {"1","2","3","4","5","6","7","8","9"}
    );
}

TEST(String, ValidMixedQuoting) {
    check(
            "\"1\",2,\"3\"\n4,\"5\",6\n\"7\",\"8\",\"9\"",
            {"1","2","3","4","5","6","7","8","9"}
    );
}

TEST(String, EmbeddedQuoteQuoteEscape) {
    check(
            R"(a""b""c,"def",ghi)",
            {R"(a"b"c)", "def", "ghi"}
    );
}
