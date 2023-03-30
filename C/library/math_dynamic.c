#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

int main() {
  int x = 20;
  int y = 5;

  printf("动态编译链接\n");
  printf("x + y = %d\n", add(x, y));
  printf("x - y = %d\n", sub(x, y));
  printf("x * y = %d\n", mul(x, y));
  printf("x / y = %d\n", div(x, y));
  return 0;
}

