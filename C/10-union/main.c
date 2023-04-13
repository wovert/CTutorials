#include <stdio.h>
//#include <stdbool.h>

union SHARE {
  char a;
  short b;
  int c;
  char buf[4];
};

enum COLOR { RED, GREEN, BLUE };
enum BOOL {false, true};
typedef enum BOOL bool;

void main() {

  union SHARE tmp;
  tmp.a = 0x01;
  tmp.b = 0x0102;
  tmp.c = 0x04030201;

  printf("a=%#X b=%#X c=%#X\n", tmp.a, tmp.b, tmp.c);
  printf("a=%p b=%p c=%p\n", (char *)&tmp.a, (short *)&tmp.b, (int *)&tmp.c);
  printf("sizeof(union)=%d\n", sizeof(tmp)); // 4

  printf("buf[0]=%#x\n", tmp.buf[0]);
  if (tmp.buf[0] == 0x01) {
    printf("Big-Endian\n");
  } else {
    printf("Little-Endian\n");
  }

  enum COLOR color = RED;
  printf("color=%d\n", color);

  bool a;
  a = false;
  printf("%d\n", a);
  printf("%d\n", false);
  printf("%d\n", true);

  return;
}
