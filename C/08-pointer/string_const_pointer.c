#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buf1[128] = "hello";
  char buf2[] = "hello";

  printf("sizeof(buf1)=%lu\n", sizeof(buf1)); // 128
  printf("sizeof(buf2)=%lu\n", sizeof(buf2)); // 6

  printf("strlen(buf1)=%lu\n", strlen(buf1)); // 5
  printf("strlen(buf2)=%lu\n", strlen(buf2)); // 5

  char *p = buf2;
  *(p+2) = 'k';
  printf("p=%s\n", p); // heklo
  printf("buf2=%s\n", buf2); // heklo
  p = "how are you";
  printf("p=%s\n", p);
  // *p = "M"; // error 字符串常量区域不能写入
  printf("p=%s\n", p);
}