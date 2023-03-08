
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int year = 0;
  int month = 0;
  int day = 0;

//  scanf("%d:%d:%d", &year, &month, &day);
//  printf("%d-%d-%d\n", year, month, day);


  char buf[1024] = "2018:10:20";

  int len = sscanf(buf, "%d:%d:%d", &year, &month, &day);

  printf("%d-%d-%d\n", year, month, day);
  printf("len=%d\n", len); // 3



  return 0;
}