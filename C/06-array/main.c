#include <stdio.h>

#define ARRAY_SIZE 10

// Ĭ�϶���0
int global_array[ARRAY_SIZE];

int main() {

//  // ��������
//  auto int array[ARRAY_SIZE];
//  int array0[ 3 + 2]; // ok
//
//  for (int i = 0; i < ARRAY_SIZE; ++i) {
//    printf("array[%d]=%c\n", i, array[i]);
//  }
//
//  for (int i = 0; i < ARRAY_SIZE; ++i) {
//    array[i] = i;
//  }
//
//  for (int i = 0; i < ARRAY_SIZE; ++i) {
//    printf("array[%d]=%c\n", i, array[i]);
//  }
//
//  // ��ʼ���б�
//  int array2[ARRAY_SIZE] = {0,1,2,3,4,5,6,7,8,9};
//
//  for (int i = 0; i < ARRAY_SIZE; ++i) {
//    printf("array2[%d]=%c\n", i, array[i]);
//  }
//
//  // C99
//  char array_char[5] = {[2] = '0', 'l', 'k'};
//  for (int i = 0; i < 5; ++i) {
//    printf("array_char[%d]=%c\n", i, array_char[i]);
//  }
//
//  int value = 2;
//
//  // C99, VLA: gcc ֧�֣� MSVC ERROR
//  int array_size_of_value[value];
//
//  const int kSize = 5; // C++ ok
//  int array_size_of_const[kSize]; // C99, VLA: gcc ֧�֣� MSVC ERROR


  int num[10] = {0}; // ����������Ԫ�س�ʼ��Ϊ0
  for (int i = 0; i < 10; ++i) {
    printf("num[%d]=%d\n", i, num[i]);
  }

  printf("num�����С%d\n", sizeof(num));
  printf("num����Ԫ�ظ���%d\n", sizeof(num)/sizeof(num[0 ]));

  return 0;
}
