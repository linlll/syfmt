#ifndef _SYFMT_H_
#define _SYFMT_H_

#include "format.h"

namespace syfmt {

template <typename... Args>
auto print(const char *formatString, Args... args) -> void {
  details::Formatter formatter(formatString, args...);

  formatter.print();
}

} // namespace syfmt

#endif // _SYFMT_H_
