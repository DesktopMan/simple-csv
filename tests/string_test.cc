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

TEST(String, UnquotedEmbeddedQuoteQuoteEscape) {
    check(
            R"(a""b""c,"def",ghi)",
            {R"(a"b"c)", "def", "ghi"}
    );
}

TEST(String, QuotedEmbeddedQuoteQuoteEscape) {
    check(
            R"("a""b""c","def",ghi)",
            {R"(a"b"c)", "def", "ghi"}
    );
}

TEST(String, EmptyUnquoted) {
    check(
            "abc,,def",
            {"abc","","def"}
    );
}

TEST(String, EmptyQuoted) {
    check(
            R"("abc","","def")",
            {"abc","","def"}
    );
}

TEST(String, UnexpectedQuote) {
    check(
            R"(a"b"c,d"e"f)",
            {""},
            result::UNEXPECTED_QUOTE
    );
}

TEST(String, EmbeddedNewline) {
    check(
            "\"a\nb\",\"c\nd\"\n\"e\nf\",\"g\nh\"",
            {"a\nb","c\nd","e\nf","g\nh"},
            result::OK
    );
}

TEST(String, InsufficientBufferSize) {
    check(
            R"("1234567890")",
            {""},
            result::INSUFFICIENT_BUFFER_SIZE
    );
}
