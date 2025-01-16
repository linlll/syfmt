#include "stdout_sink.h"

syfmt::details::StdoutSink::StdoutSink() : Sink(stdout) {}

auto syfmt::details::StdoutSink::sink_it(const char* buffer, size_t size) -> void {
  std::fwrite(buffer, 1, size, fp_);
}
