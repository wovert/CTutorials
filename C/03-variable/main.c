#include <stdio.h>

int main() {
  int num;
  num = 20;

  int *numAddr = &num;
  num = 21;

  printf("sizeof value:%d\n", sizeof(num));
  printf("address of value: %#x\n", &num);

  return 0;
}
