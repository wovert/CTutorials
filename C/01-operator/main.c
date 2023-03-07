#include <stdio.h>

int main() {
  // 0000 0011
  // 0001 1000 8 + 16 = 24 = 3 * 2^3 = 3 x 8
  int a = 3;
  a <<= 3;
  printf("a << 3 = %d\n", a);

  // 0001 1110
  int b = 30;
  b >>= 3; // 30/ 2^3 = 30/8 = 3
  printf("b >> 3 = %d\n", b);

  return 0;
}
