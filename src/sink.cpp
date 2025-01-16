#include "sink.h"

syfmt::details::Sink::Sink() : fp_(nullptr) {}

syfmt::details::Sink::Sink(FILE* fp) : fp_(fp) {}
