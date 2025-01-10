#include "gtest/gtest.h"

#include "syfmt.h"

TEST(syfmt, syfmt) {
  EXPECT_NO_THROW(syfmt::print("hello {}\n", "world"));
  EXPECT_NO_THROW(syfmt::print("{}{}{}{}{}\n", 'h', 'e', 'l', 'l', 'o'));
  EXPECT_NO_THROW(syfmt::print("{} {} {} {} {}\n", 'a', 123, (float)1.23, (double)1.23, "c-style string"));
}
