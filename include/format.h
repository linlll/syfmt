#ifndef _FORMAT_H_
#define _FORMAT_H_

#include <cstdio>
#include <cstring>
#include <assert.h>
#include <string>

#include "args.h"

namespace syfmt {
namespace details {

template <typename... Args>
class Formatter {
public:
  Formatter() = delete;
  Formatter(const char *formatString, Args... args)
    : formatString_(formatString), argStore_{args...} { }

public:
  auto print() -> void {
    enum { MAX_BUFFER = 500 };
    char buffer[MAX_BUFFER];

    size_t len = strlen(formatString_);
    const char *from = formatString_, *end = formatString_ + len;
    char *to = buffer;
    size_t n = 0;
    std::string s;
    while (from <= end) {
      char c = *from;
      switch (c) {
      case '{':
        s = argStore_.store_[n++].to_string();
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

private:
  const char *formatString_;
  ArgStore<Args...> argStore_;
};

} // namespace details
}  // namespace syfmt

#endif  // _FORMAT_H_
