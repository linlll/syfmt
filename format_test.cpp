#include "format.h"

int main(int argc, char const *argv[]) {
  /* code */

  syfmt::print("hello {}\n", "world");

  syfmt::print("{}{}{}{}{}\n", 'h', 'e', 'l', 'l', 'o');

  syfmt::print("{} {} {} {} {}\n", 'a', 123, (float)1.23, (double)1.23, "c-style string");

  return 0;
}
