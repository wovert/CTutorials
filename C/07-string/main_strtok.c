
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char str[] = "football#basketball#baseball";

//  char *p1 = strtok(str, "#");
//  printf("p1=%s\n", p1);
//
//  char *p2 = strtok(NULL, "#");
//  printf("p2=%s\n", p2);
//
//  char *p3 = strtok(NULL, "#");
//  printf("p2=%s\n", p3);
//
//  char *p4 = strtok(NULL, "#");
//  printf("p2=%s\n", p4);


  char *dst[10] = {NULL}; // 初始化指针数组元素全部为 NULL

  int i = 0;
  do {
    dst[i] = i == 0 ? dst[i] = strtok(str, "#") : strtok(NULL, "#");
  } while(dst[i++] != NULL);

  i = 0;
  while(dst[i] != NULL) {
    printf("dst[%d]=%s\n", i, dst[i++]);
  }
//  for (int j = 0; j < sizeof(dst)/sizeof(char *); ++j) {
//    printf("dst[%d]=%s\n", j, dst[j]);
//  }
  return 0;
}