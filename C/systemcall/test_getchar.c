#include <stdio.h>

int main() {
  char c = -1;
  // 阻塞
  c = getchar(); // 从标准输入获取一个字符

  putchar(c); // 输出标准输出
  return 0;
}
