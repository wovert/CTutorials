#include <stdio.h>

void fun(void) {

  int i = 0;
  for(i=0; i<10; i++) {
    printf("fun() => i=%d\n", i);
  }
}

int main(int argc, char **argv) {

  
  int i;
  for(i=0; i<argc; i++) {
    printf("argv[%d]=%s\n", i, argv[i]);
  }

  fun();
  printf("hello world\n");

  return 0;
}
