#include <stdio.h>

void f(int *);
void f2(int **);

int main() {
  int i = 15;
  int *p = &i;
  printf("i=%d,addr=%p\n", i, &i);
  printf("p=%p,addr=%p\n", p, &p);
  printf("-------------------\n");

  // 变量p的内容是 变量 i 的地址
  // 等于p变量没有使用
  f(p);
  printf("-------------------\n");
  printf("i=%d,addr=%p\n", i, &i);
  printf("p=%p,addr=%p\n", p, &p);
  printf("-------------------\n");

  // &p是指针变量的地址
  f2(&p);
  
  printf("-------------------\n");
  printf("i=%d,addr=%p\n", i, &i);
  printf("p=%p,addr=%p\n", p, &p);  
  printf("-------------------\n");
  
  return 0;
}

void f(int *q) {
  printf("create new pointer variable: q=%p,addr=%p\n", q, &q);  
  *q = 0X0010;
}

// **r 是指针变量的地址
void f2(int **r) {
  printf("r=%p,addr=%p\n", r, &r);  
  // **r 修改指针变量内容的地址的内容
  **r = 0X0011;

  // 修改了指针变量地址的内容修改了新的地址
  *r = (int *)0X0011;
}
