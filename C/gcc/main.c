#include <stdio.h>

int main() {
  int a = 3;
#ifdef DEBUG
  printf("Debug info\n");
#endif
  printf("Hello world\n");
  return 0;
}	
