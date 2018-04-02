#include <stdio.h>

int main() {
  char name[20];
  printf("请输入名字：");
  fgets(name, sizeof(name), stdin);
  printf("My name is %s\n", name);
  return 0;
}