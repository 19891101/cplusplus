#include <iostream>
#include <type_traits>
#include <functional>

template <typename T, typename = std::enable_if_t<std::is_array<T>::value>>
void OutArray(T& arg) {
  std::cout << "is array: " << std::extent<T>::value << "\n";	
}

template <typename T, typename = std::enable_if_t<!std::is_const<T>::value>>
void OutNotConst(T& arg) {
  std::cout << "not const\n";	
}

void PrintString(const std::string& s) {
  std::cout << "[" << s << "]\n";
}

template <typename T>
void PrintT(T arg) {
  std::cout << "template called\n";
  PrintString(arg);
}

void PrintT(std::reference_wrapper<const std::string> arg) {
  std::cout << "non-template called\n";
  PrintString(arg);
}



