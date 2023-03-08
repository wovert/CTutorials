#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

  char *str1 = "cn";
  char *str2 = "kr";
  char *str3 = "jp";

  // 字符指针数组
  // 指针类型: char *[]
  // 指针指向类型：char []
  char *countries[] = {str1, str2, str3};


  // 指针类型: char *[]
  // 指针指向类型：char []
  char *countries2[] = {'a', 'b', 'c'};

  // 指针类型 char **
  // 指针指向类型 char *
  char **temp = countries;
  char **temp2 = countries2;

  printf("countries sizeof=%d\n", sizeof(countries));

  printf("temp=%s[%p]\n", *temp, temp);
  // 指针指向类型 char * x 1 =
  temp++;
  printf("temp++=%s[%p]\n", *temp, temp);

  printf("---------------------\n");

  printf("countries2 sizeof=%d\n", sizeof(countries2));

  printf("temp2=%c[%p]\n", *temp2, temp2);
  // 指针指向类型 char * x 1 =
  temp2++;
  printf("temp2++=%c[%p]\n", *temp2, temp2);
  printf("---------------------\n");


  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;


  int *arr[4] = {10,20,30,40};

  // 指针类型 int *
  // 指针指向类型 int = 4
  int *arr1 = arr;

  // 指针类型 int **
  // 指针指向类型 int * = 8
  int **arr2 = arr;

  // 指针类型 char **
  // 指针指向类型 char * = 8
  char **arr3 = arr;

  printf("arr1=%d[%p]\n", *arr1, arr1);
  arr1++;
  printf("arr1++=%d[%p]\n", *arr1, arr1);
  arr1++;
  printf("arr1++=%d[%p]\n", *arr1, arr1);

  printf("-------------\n");

  printf("arr2=%d[%p]\n", *arr2, arr2);
  arr2++;
  printf("arr2++=%d[%p]\n", *arr2, arr2);
//  arr1++;
//  printf("arr1++=%d[%p]\n", *arr1, arr1);

  printf("-------------\n");


  printf("arr3=%d[%p]\n", *arr3, arr3);
  arr3++;
  printf("arr3++=%d[%p]\n", *arr3, arr3);
//  arr1++;
//  printf("arr1++=%d[%p]\n", *arr1, arr1);


  printf("-------------\n");


  char cp[6] = {'A', 'B', 'C', 'D', 'E','F'};

  // 指针自身类型：char (*) [6]
  // 指针指向类型：char () [6] 指针指向了6个数组元素类型是 char
  char (*pcp) [5] = &cp;

  printf("%c,%d[%p]\n", *((char *)pcp), *((char *)pcp),pcp);
  printf("%c, %d[%p]\n", *pcp[0], *pcp[0], &pcp[0]);
  printf("sizeof(char[5])=%d\n", sizeof(char[5]));
  pcp++;
  printf("%c, %d[%p]\n", *pcp[0], *pcp[0], &pcp[0]);
  return 0;
}