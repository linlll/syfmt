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
  void sink_it(const char *buffer, size_t size);

private:
  void setFp(FILE *fp);

};

} // namespace details
}  // namespace syfmt

#endif // _FILE_SINK_H_
