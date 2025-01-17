#include "syfmt.h"

auto syfmt::setSink(details::Sink* sink) -> void {
  syfmt::details::Registry::getInstance()->setSink(sink);
}
