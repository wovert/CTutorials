#include <stdio.h>

void fun();
// i 没有写类型，可以是任意类型(在MingGW编译器可以通过编译)
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

int main(void) {
  fun();
  fun();
//  fun1(10);
//  fun2("abc");
//  fun3(10, "abc"); 


  return 0;
}
void fun() {
  // auto是变量类型 自动变量，int 变量数据类型
  auto int value = 0;

  //
  static int static_count;

  printf("value=%d\n", value);
  printf("static_count=%d\n", static_count);
  static_count++;

}
