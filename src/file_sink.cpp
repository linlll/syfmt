#include "file_sink.h"

#include <cstring>
#include <cstdlib>

syfmt::details::FileSink::FileSink(const char* file, const char *mode) {
  FILE *fp = std::fopen(file, mode);
  if (fp == nullptr) {
    char buffer[100] = "file not open";
    std::fwrite(buffer, 1, strlen(buffer), stderr);
    std::exit(-1);
  }

  setFp(fp);
}

syfmt::details::FileSink::~FileSink() {
  std::fclose(fp_);
}

auto syfmt::details::FileSink::sink_it(const char* buffer, size_t size) -> void {
  std::fwrite(buffer, 1, size, fp_);
}

auto syfmt::details::FileSink::setFp(FILE* fp) -> void {
  fp_ = fp;
}
