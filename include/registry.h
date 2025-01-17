#ifndef _REGISTER_H_
#define _REGISTER_H_

#include "format.h"
#include "sink.h"

namespace syfmt {
namespace details {

class Registry {

public:
  template <typename... Args>
  auto print(const char *formatString, Args... args) -> void;

  auto setSink(Sink *sink) -> void;

  static auto getInstance() -> Registry*;

private:
  Registry();
  ~Registry();

private:
  Sink *sink_;
};

} // namespace details
} // namespace syfmt

#include "registry-inl.h"

#endif // _REGISTER_H_
