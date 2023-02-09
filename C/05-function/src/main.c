#include <stdio.h>

// 宏参数没有类型
#define MAX(a, b) (a) > (b) ? (a) : (b)

// 定义多行宏
#define IS_HEX_CHARACTER(ch) \
((ch) >= '0' && (ch) <= '9') || \
((ch) >= 'A' && (ch) <= 'F') || \
((ch) >= 'a' && (ch) <= 'f')

int max(int a, int b) {
  return a > b ? a : b;
}

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

void demoMax() {
  int max1 = MAX(1, 3);
  int max2 = MAX(1, MAX(3, 4));

  printf("max1=%d\n", max1); // 3
  printf("max2=%d\n", max2); // 4

  int max3 = max(1, max( 3, 4)); // 函数参数需要计算
  printf("max3=%d\n", max3);

  int max4 = MAX(max1++, 3); // 替换：(max1++) > (3) ? (max1++) : (3);
  printf("max4=%d\n", max4);

  printf("is G a hex character? %d\n", IS_HEX_CHARACTER('G')); // 0

}

#define DEBUG

// 在CMakeList.txt 中声明
void dump(char *message) {
#ifdef DEBUG
  puts(message);
#endif
}

int main(void) {
//  fun();
//  fun();
//  fun1(10);
//  fun2("abc");
//  fun3(10, "abc"); 

  demoMax();

  dump("hello world");

  // MinGW
  printf("__STDC_VERSION__: %ld\n", __STDC_VERSION__);
#if __STDC_VERSION__ >= 201112
  puts("C11!!");
#elif __STDC_VERSION__ >= 199901
  puts("C99");
#else
  puts("Maybe C90");
#endif

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
