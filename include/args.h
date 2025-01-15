#ifndef _ARGS_H_
#define _ARGS_H_

#include "value.h"

namespace syfmt {
namespace details {

template <typename... Args>
struct ArgStore {
  static constexpr size_t num_args = sizeof...(Args);
  value store_[num_args];

  ArgStore(Args... args) : store_{args...} {}
};

} // namespace details
}  // namespace syfmt

#endif // _ARGS_H_
