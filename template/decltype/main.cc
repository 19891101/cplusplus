#include "decltype.h"
#include <vector>

int main() {
  int a[4];
  std::vector<int> v = {1, 2, 3, 4};
  std::allocator<int> al;
  std::cout << len(a) << "\n";
  std::cout << len("hello") << "\n";
  std::cout << len(v) << "\n";
  std::cout << len(al) << "\n";
  return 0;
}

