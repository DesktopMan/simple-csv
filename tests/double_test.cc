#include <gtest/gtest.h>

#include "util.hpp"

TEST(Double, Valid) {
    check<double>(
            "-5.7,0.0,3.4",
            {-5.7, 0.0, 3.4}
    );
}
