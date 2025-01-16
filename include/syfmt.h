#ifndef _SYFMT_H_
#define _SYFMT_H_

#include "format.h"
#include "stdout_sink.h"
#include "file_sink.h"
#include "register.h"

namespace syfmt {

template <typename... Args>
auto print(const char *formatString, Args... args) -> void {
  // details::StdoutSink *sink = new details::StdoutSink();
  details::FileSink *sink = new details::FileSink("./test.txt", "a+");
  details::Formatter formatter(sink, formatString, args...);

  formatter.print();
}

} // namespace syfmt

#endif // _SYFMT_H_
