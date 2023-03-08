
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int year = 2023;
  int month = 3;
  int day = 8;

  char buf[1024] = "";

//  printf("year=%d mont=%d day=%d\n", year, month, day);
  int len = sprintf(buf, "year=%d mont=%d day=%d\n", year, month, day);
  printf("buf[%s]\n", buf);

  printf("%d\n", strlen(buf));
  printf("len=%d\n", len);

  return 0;
}