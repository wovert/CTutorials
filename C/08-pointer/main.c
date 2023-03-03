#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pointStepWidth();
void yePointer();
void emptyPointer();
void anyPointer();
int main() {
//  yePointer();
//  emptyPointer();
anyPointer();
//  pointStepWidth();
  return 0;
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
