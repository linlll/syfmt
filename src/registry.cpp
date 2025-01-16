#include "registry.h"
#include "stdout_sink.h"

#include <cstdio>

syfmt::details::Registry::Registry() : sink_(new StdoutSink()) {}

auto syfmt::details::Registry::setSink(Sink* sink) -> void {
  sink_ = sink;
}
