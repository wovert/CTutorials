#include <stdio.h>

// i 没有写类型，可以是任意类型
int fun1(i) {
  printf("%d\n", i);
  return 0;
}

int fun2(i) {
  printf("%s\n", i);
  return 0;
}

int fun3() {
  printf("fun33333333\n");
  return 0;
}

int main() {
    fun1(10);
    fun2("abc");
    fun3(10, "abc");


    return 0;
}