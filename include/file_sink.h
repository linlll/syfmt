#ifndef _FILE_SINK_H_
#define _FILE_SINK_H_

#include "sink.h"

namespace syfmt {
namespace details {

class FileSink : public Sink {
public:
  FileSink() = delete;
  FileSink(const char *file, const char *mode);
  ~FileSink();

public:
  auto sink_it(const char *buffer, size_t size) -> void;

private:
  auto setFp(FILE *fp) -> void;

};

} // namespace details
}  // namespace syfmt

#endif // _FILE_SINK_H_
