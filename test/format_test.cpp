#include "gtest/gtest.h"

#include "syfmt.h"

TEST(syfmt, empty) {
  EXPECT_NO_THROW(syfmt::print("\n"));
}

TEST(syfmt, char) {
  EXPECT_NO_THROW(syfmt::print("The upper character of {} is {}\n", 'a', toupper('a')));
}

TEST(syfmt, integral) {
  EXPECT_NO_THROW(syfmt::print("The price fo the shirt is {} punds and {} pence\n", 9, 15));
}

TEST(syfmt, float_point) {
  float height = 1.7, weight = 66.6;
  double bmi = weight / height / height;
  EXPECT_NO_THROW(
    syfmt::print("My height is {} meters, and my weight is {} kilogram, then my BMI is {}\n", height, weight, bmi)
  );
}

TEST(syfmt, cstring) {
  EXPECT_NO_THROW(syfmt::print("hello {}\n", "world"));
}

TEST(syfmt, mixed) {
  EXPECT_NO_THROW(syfmt::print("My name is {}, I like running very much. Now my personal best of {} kilometer is {} minutes and {} seconds.\n", "LIN", 5, 22, 30));
}

TEST(syfmt, file_sink) {
  syfmt::details::FileSink *sink = new syfmt::details::FileSink("./test.txt", "w+");
  syfmt::setSink(sink);
  EXPECT_NO_THROW(syfmt::print("This is a test.\n"));
}
