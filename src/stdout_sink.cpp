#include "stdout_sink.h"

syfmt::details::StdoutSink::StdoutSink() : Sink(stdout) {}

void syfmt::details::StdoutSink::sink_it(const char* buffer, size_t size) {
  std::fwrite(buffer, 1, size, fp_);
}
