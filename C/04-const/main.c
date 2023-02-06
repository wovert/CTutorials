#include <stdio.h>

#define COLOR_RED 0xFF0000

int main() {
  const int red = 0xFF0000;
  const int green = 0xFF0000;
  const int blue = 0xFF0000;

  printf("red:%d\n", red);

  int *p_red = &red;
  *p_red = 0xEE0000;
  printf("red:%d\n", red);

  printf("COLOR_RED: %d\n", COLOR_RED);

  // 去除宏定义
#undef COLOR_RED
//  printf("COLOR_RED: %d\n", COLOR_RED);

  return 0;
}
