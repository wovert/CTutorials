#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pointStepWidth();
void yePointer();
void emptyPointer();
void anyPointer();
void pointer();
int main() {
//  pointer();
//  yePointer();
//  emptyPointer();
//anyPointer();
//  pointStepWidth();


  return 0;
}
void pointer() {
  char c = 'a';
  char *p = &c;

  printf("p=%p\n", p);
  printf("&c=%p\n", &c);

  char *name = &c;
  printf("name=%p\n", name);

  char *p1 = p;
  printf("p=%p\n", p);
  printf("p1=%p\n", p1);

//  p = NULL;

  char **pp = &p;
  printf("*pp=%p\n", *pp);

  printf("*p=%c\n", *p);
  printf("*p1=%c\n", *p1);
  printf("**pp=%c\n", **pp);

  printf("p+1=%p\n", p+1); // p地址加p指针类型 + 1
  printf("*p+1=%c\n", *p+1); // p指针指向的空间 + 1

//  printf("*(p+1)=%p\n", *(p+1)) // 野指针


}

// 万能指针
void anyPointer() {
  int i = 10;
  short h = 20;

  void *p = (void *)&i;
  void *q = (void *)&h;

//  printf("%d\n", *p); // p 是void*类型，不知道取得多少字节zhizhib
  printf("%d\n", *(int *)p); // 10
  printf("%d\n", *(short *)q); // 20
}

// 空指针
void emptyPointer() {
  int *p = NULL;
  *p = 200;
  printf("*p=%d\n", *p);
}
// 野指针
void yePointer() {
  int *p;
  *p = 200;
}

// 指针的步长和宽度
void pointStepWidth() {
  int num = 0x11223344;

  char *pChar = (char *)&num;
  short *pShort = (short *)&num;
  int *pInt = &num;

  printf("%x\n", *pChar); // 44
  printf("%x\n", *pShort); // 3344
  printf("%x\n", *pInt); // 11223344


  printf("%u\n", pChar);
  printf("%u\n", pShort);
  printf("%u\n", pInt);

  printf("%u\n", pChar + 1); // 步长1个字节
  printf("%u\n", pShort + 1); // 步长2个字节
  printf("%u\n", pInt + 1); // 步长4个字节
}
