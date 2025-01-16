#ifndef _REGISTER_INL_H_
#define _REGISTER_INL_H_

template <typename... Args>
auto syfmt::details::Registry::print(const char *formatString, Args... args) -> void {
  details::Formatter formatter(sink_, formatString, args...);

  formatter.print();
}

#endif // _REGISTER_INL_H_
