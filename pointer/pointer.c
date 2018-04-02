#include <stdio.h>

int main() {
  
  // p 是指针变量，p只能存储 int类型的变量地址
  // &p=0028FF2C
  int *p;

  // &i=0028FF28
  int i = 10;
  
  // &j=0028FF24
  int j;

  // 变量 i指向内容的地址赋值给
  // 指针变量p(可以存储变量内容的地址)
  p = &i;

  // 获取复制指针变量的内容赋值给变量 j
  j = *p;
  
  // 修改变量j的值
  j = 20;

  printf("j=%d, j pointer=%p\n", j, &j);
  printf("i=%d, i pointer=%p\n", i, &i);
  printf("p=%p, p pointer=%p\n", p, &p);  
  
  return 0;
}