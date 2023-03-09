#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void demo01();
void demo02();
int add(int a, int b) {
  return a + b;
}

int sub(int a, int b) {
  return a - b;
}

int mul(int a, int b) {
  return a * b;
}

int divs(int a, int b) {
  return a / b;
}

// 参数：值传递
void change(int (*p1)(int a, int b)) {
  p1 = add;
}

// 参数：指针引用
void changeTrue(int (**p1)(int a, int b)) {
  *p1 = add;
}

void demo01() {
  int *px[10];

  // 定义函数指针
  int (*pn[4])(int a, int b) = {add, sub, mul, divs};
  int a = 10;
  int b = 5;

  for (int i = 0; i < 4; ++i) {
    printf("result:%d\n", pn[i](a, b));
  }

  int (*p2)(int a, int b) = add;
  printf("p2(a,b)=%d\n", p2(a, b));

  p2 = sub;
  printf("p2(a,b)=%d\n", p2(a, b));

  change(p2);
  printf("p2(a,b)=%d\n", p2(a, b));

  changeTrue(&p2);
  printf("p2(a,b)=%d\n", p2(a, b));
}




int main() {

  demo01();


  return 0;
}
