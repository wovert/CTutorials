
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // [-+0-9] 其他为 0
  char num[] = "#-1234";
  char str[] = "3.14";

  // 字符转整数
  int sum = atoi(num);
  printf("sum=%d\n", sum);

  float salary = atof(str);
  printf("salary=%.2f\n", salary);

  return 0;
}