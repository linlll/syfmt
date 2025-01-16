#ifndef _SINK_H_
#define _SINK_H_

#include <cstdio>

namespace syfmt {
namespace details {

class Sink {
public:
  Sink();
  Sink(FILE *fp);

public:
  virtual auto sink_it(const char* buffer, size_t size) -> void = 0;

protected:
  FILE *fp_;

};

} // namespace details
}  // namespace syfmt

#endif // _SINK_H_
