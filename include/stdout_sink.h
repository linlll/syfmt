#ifndef _STDOUT_SINK_H_
#define _STDOUT_SINK_H_

#include "sink.h"

namespace syfmt {
namespace details {

class StdoutSink : public Sink {
public:
  StdoutSink();

public:
  void sink_it(const char *buffer, size_t size);

private:

};

} // namespace details
}  // namespace syfmt

#endif // _STDOUT_SINK_H_
