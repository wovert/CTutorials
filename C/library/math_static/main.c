#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "div.h"
#include "mul.h"

int main() {
  int x = 15;
  int y = 5;

  printf("x+y=%d\n", add(x, y));
  printf("x-y=%d\n", sub(x, y));
  printf("x*y=%d\n", mul(x, y));
  printf("x/y=%d\n", div(x, y));
  return 0;
}



