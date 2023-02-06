#include <stdio.h>
#include <malloc.h>
#include <limits.h>

typedef enum COLOR { GREEN, RED, YELLOW} color;

void charDatatype();
void decimalDatype();
void intDatatype() {
  char c = 'A';
  short short_int = 0;
  int i = 0;
  long long_int = 0;
  long long longlong_int = 0;

  unsigned int unsigned_int = 123;
  unsigned long unsigned_long = 789;

  // %c: char
  // %hd: short decimal
  // %d: decimal
  // %ld: long decimal
  // %lld: long long decimal
  // %hu: unsigned short decimal
  // %x: hex
  // %o: oct
  // %n: new line
  // size_t

  size_t size_of_int = sizeof(int);
  printf("char: %llu\n", sizeof(char));
  printf("short: %llu\n", sizeof(short));
  printf("int: %llu\n", sizeof(int));
  printf("long: %llu\n", sizeof(long));
  printf("long long: %llu\n", sizeof(long long));

  printf("min int %d, max int %d\n", INT_MIN, INT_MAX);
  printf("unsigned max int %u\n", UINT_MAX);

  printf("min long %ld, max long %ld\n", LONG_MIN, LONG_MAX);
  printf("unsigned max long %lu\n", ULONG_MAX);
  printf("unsigned max long long %llu\n", ULLONG_MAX);


  // int=4byte=-2^31~2^(31-1)
  int num = 17979878977;
  printf("num = %i\n", num);

  // long int = 8byte
  // li 或 lid 输出 long 类型的数据
//    long int num1 = 17979878977;
  long num1 = 17979878977;
  printf("num = %li\n", num1);

  // 64 bit 没有区别
  // 32 bit 下 long 占用4个字节，long long 占用8个字节, %lli or %lld
  long long num2 = 17979878977;
  printf("num = %lli, long long = %i, long = %i\n", num2, sizeof(num2), sizeof(num1));

  // short => %hi, %hd
  // signed => +-
  // unsigned => 0+ %u
  // unsigned short => %hu
  // unsigned int => %iu
  // sungined long => %lu

}
void enumDataType() {
  color myColor = GREEN;
  myColor = 10;
  printf("mycolor=%d\n", myColor);
  char *p = malloc(10);
}



int main(int argc, const char * argv[]) {

//  intDatatype();
  charDatatype();
//  enumDataType();
//  decimalDatype();
  return 0;
}
void decimalDatype() {
  float f_pi = 3.14F; // float literal 6位有效位数 保7留8
  double d_pi = 3.1415926; // 15~16 有效位数

  float lat = 39.9081f;
  int lat_int = lat * 1e4;
  printf("%f\n", 39.9080f - lat);
  printf("%d\n", lat_int);

  float money = 3.14f; // error

}
void charDatatype() {
  // 字符集 ASCII 127
  char char_1 = '1';
  char char_0 = '0';
  char newline = '\n'; // 10
  char empty = 0; // \0, NULL
  char char_A = 65;
  char char_a = 97;
  char char_oct_1 = '\61'; // 6x8^1 + 1x8^0 = 49
  char char_x_1 = '\x31'; // 3x16^1 + 1 = 49

  char num = 127 + 2;
  char color = 0xFF;

  /**
   * literal
   * \n: newline
   * \b: backspace
   * \r: return
   * \t: table
   * \': ' 字符字面量
   * \": " 字符串字面量
   */

  // Unicode CJK C95支持
  wchar_t zhong = L'中';
  wchar_t zhong_hex = L'\u4E2D'; // Code point

  printf("char_1=%d, %c\n", char_1, char_1);
  printf("char_0=%d, %c\n", char_0, char_0);
  printf("newline=%d, %c\n", newline, newline);
  printf("empty=%d, %c\n", empty, empty);
  printf("char_A=%d, %c\n", char_A, char_A);
  printf("char_a=%d, %c\n", char_a, char_a);
  printf("char_oct_49=%d, %c\n", char_oct_1, char_oct_1);
  printf("char_x_1=%d, %c\n", char_x_1, char_x_1);

  // Clion 编译器默认编码: GBK 编码
  // MingGW 编译器默认编码: UTF-8 编码
  printf("zhong=%d, %c\n", zhong, zhong);
  printf("zhong_hex=%d, %c\n", zhong_hex, zhong_hex);

  /**
   * char num = 129;
   * char 有符号范围： -128~127
   * 129 = 1000 0001
   * 1符号位：代表负数 即 -1
   * -1 原码：1000 0001
   * -1 反码：1111 1110
   * -1 补码：1111 1111
   * -1 计算机以 -127 存入
   */
  //
  printf("num=%d\n", num); // -127
  printf("num=%d\n", 129); // 129
  printf("color=%d\n", color); // -1
}
