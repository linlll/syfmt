#ifndef _FORMAT_H_
#define _FORMAT_H_

#include <cstdio>
#include <cstring>
#include <assert.h>

namespace syfmt {

template <typename... Args>
struct ArgStore {
  static constexpr size_t num_args = sizeof...(Args);
  const char *store_[num_args];

  ArgStore(Args... args) : store_{args...} {}
};

template <typename... Args>
auto doPrint(const char *formatString, ArgStore<Args...> argStore) {
  enum { MAX_BUFFER = 500 };
  char buffer[MAX_BUFFER];

  size_t len = strlen(formatString);
  const char *from = formatString, *end = formatString + len;
  char *to = buffer;
  size_t n = 0;
  while (from <= end) {
    char c = *from;
    switch (c) {
    case '{':
      strcpy(to, argStore.store_[n++]);
      to += strlen(argStore.store_[n++]);
      from += 2;
      break;
    default:
      memcpy(to, from, 1);
      ++to;
      ++from;
      break;
    }
  }

  std::fwrite(buffer, sizeof(char), strlen(buffer), stdout);
}

template <typename... Args>
auto print(const char *formatString, Args... args) -> void {
  const auto argStore = ArgStore<Args...>(args...);

  doPrint(formatString, argStore);
}

}  // namespace syfmt

#endif  // _FORMAT_H_
