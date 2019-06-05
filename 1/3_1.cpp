#include <iostream>
#include <cstdint>
#include <type_traits>

using namespace std;

template<typename T> T gcd(T m, T n) {
  static_assert(is_integral<T>::value == true, "specified typename is not a integral type");
  if (m < n) swap(m, n);
  if (n == 0) return m;
  return gcd(n, m % n);
}

template<typename T> T lcm(T m, T n) {
  return m * n / gcd(m, n);
}

int main(void) {
  uintmax_t m, n;
  cin >> m >> n;
  cout << lcm(m, n) << endl;
  return 0;
}
