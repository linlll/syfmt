#ifndef _SYFMT_H_
#define _SYFMT_H_

#include "format.h"
#include "stdout_sink.h"
#include "file_sink.h"
#include "registry.h"
#include "sink.h"

namespace syfmt {

template <typename... Args>
auto print(const char *formatString, Args... args) -> void {
  details::Registry::getInstance()->print(formatString, args...);
}

auto setSink(details::Sink *sink) -> void;

} // namespace syfmt

#endif // _SYFMT_H_
