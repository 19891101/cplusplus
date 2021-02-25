#include <functional>
#include <iostream>
#include <type_traits>

template <typename T, unsigned N> std::size_t len(T (&)[N]) {
  std::cout << "array called\n";
  return N;
}


/*
  decltype会返回最后一个参数的类型
  t.size()之所以加void, 是为了防止t.size()的返回值重载了逗号表达式
*/
template <typename T>
auto len(const T &t) -> decltype((void)(t.size()), typename T::size_type()) {
  std::cout << "size called\n";
  return t.size();
}

std::size_t len(...) { return 0; }

