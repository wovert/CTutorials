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

  printf("p+1=%p\n", p+1); // p��ַ��pָ������ + 1
  printf("*p+1=%c\n", *p+1); // pָ��ָ��Ŀռ� + 1

//  printf("*(p+1)=%p\n", *(p+1)) // Ұָ��


}

// ����ָ��
void anyPointer() {
  int i = 10;
  short h = 20;

  void *p = (void *)&i;
  void *q = (void *)&h;

//  printf("%d\n", *p); // p ��void*���ͣ���֪��ȡ�ö����ֽ�zhizhib
  printf("%d\n", *(int *)p); // 10
  printf("%d\n", *(short *)q); // 20
}

// ��ָ��
void emptyPointer() {
  int *p = NULL;
  *p = 200;
  printf("*p=%d\n", *p);
}
// Ұָ��
void yePointer() {
  int *p;
  *p = 200;
}

// ָ��Ĳ����Ϳ��
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

  printf("%u\n", pChar + 1); // ����1���ֽ�
  printf("%u\n", pShort + 1); // ����2���ֽ�
  printf("%u\n", pInt + 1); // ����4���ֽ�
}
