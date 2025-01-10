#ifndef _FORMAT_H_
#define _FORMAT_H_

#include <cstdio>
#include <cstring>
#include <assert.h>
#include <string>

namespace syfmt {

struct value {
  enum {
    NONE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    CSTRING /*c-style string*/
  } type_;

  union {
    char c;
    int i;
    float f;
    double d;
    const char *p;
  } value_;

  auto to_string() -> std::string {
    switch (type_) {
    case CHAR: return std::string(1, value_.c);
    case INT: return std::to_string(value_.i);
    case FLOAT: return std::to_string(value_.f);
    case DOUBLE: return std::to_string(value_.d);
    case CSTRING: return std::string(value_.p);
    default:
      break;
    }
    return {};
  }

  template <typename T>
  value(T arg) : type_(NONE) {}

  value(char arg) : type_(CHAR) { value_.c = arg; }
  value(int arg) : type_(INT) { value_.i = arg; }
  value(float arg) : type_(FLOAT) { value_.f = arg; }
  value(double arg) : type_(DOUBLE) { value_.d = arg; }
  value(const char *arg) : type_(CSTRING) { value_.p = arg; }
};

template <typename... Args>
struct ArgStore {
  static constexpr size_t num_args = sizeof...(Args);
  value store_[num_args];

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
  std::string s;
  while (from <= end) {
    char c = *from;
    switch (c) {
    case '{':
      s = argStore.store_[n++].to_string();
      strcpy(to, s.c_str());
      to += s.size();
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
