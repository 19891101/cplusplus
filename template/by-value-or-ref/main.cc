#include "value_or_ref.h"

struct C {};

int main() {
  int a[4];
  std::string s = "test";
  C c;
  const C cc;
  // OutArray(c);
  // OutArray(cc);
  OutArray("hi");
  // OutArray(s);
  OutArray(a);

  OutNotConst(c);
  // OutNotConst(cc);

  PrintT(std::cref(s));

  return 0;
}

