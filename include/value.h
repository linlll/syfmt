#ifndef _VALUE_H_
#define _VALUE_H_

#include <string>

namespace syfmt {
namespace details {

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

} // namespace details
}  // namespace syfmt

#endif // _VALUE_H_
