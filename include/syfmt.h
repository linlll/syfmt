#ifndef _SYFMT_H_
#define _SYFMT_H_

#include "format.h"
#include "stdout_sink.h"
#include "file_sink.h"
#include "registry.h"

namespace syfmt {

template <typename... Args>
auto print(const char *formatString, Args... args) -> void {
  static details::Registry registry;

  // details::FileSink *sink = new details::FileSink("./test.txt", "w+");
  // registry.setSink(sink);

  registry.print(formatString, args...);
}

} // namespace syfmt

#endif // _SYFMT_H_
