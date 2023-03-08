#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char dest1[128] = "abc123";
  char dest2[128] = "abc123";
  char dest3[128] = "abc123";
  char source[128] = "he\0world";


  // str2 复制到 str1中
  strcpy(dest1, source);
  printf("dest1=%s\n", dest1);

  // 复制两个字符 he\000
  strncpy(dest2, source, 5);
  printf("dest2=%s\n", dest2);

  return 0;
}