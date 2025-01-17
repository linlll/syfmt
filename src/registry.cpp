#include "registry.h"
#include "stdout_sink.h"

#include <cstdio>

syfmt::details::Registry::Registry() : sink_(new StdoutSink()) {}

syfmt::details::Registry::~Registry() {}

auto syfmt::details::Registry::setSink(Sink* sink) -> void {
  sink_ = sink;
}

auto syfmt::details::Registry::getInstance() -> Registry* { 
  static Registry *registry = new Registry();
  return registry;
}
