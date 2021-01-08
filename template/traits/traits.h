#include <iostream>
#include <type_traits>

#define DEFINE_HAS_MEMBER(Member)                                  \
  template <typename, typename = std::void_t<>>                    \
  struct HasMemberT_##Member : std::false_type {};                 \
  template <typename T>                                            \
  struct HasMemberT_##Member<T, std::void_t<decltype(&T::Member)>> \
      : std::true_type {};

DEFINE_HAS_MEMBER(member_a);
DEFINE_HAS_MEMBER(member_b);

template <typename T,
          typename std::enable_if_t<HasMemberT_member_a<T>::value, int> = 0>
void Set(T &t) {
  std::cout << "Has member a" << '\n';
  t.member_a = 1;
}

template <typename T, std::enable_if_t<!HasMemberT_member_a<T>::value, int> = 0>
void Set(T &t) {
  std::cout << "Has member b" << '\n';
  t.member_b = 2;
}

