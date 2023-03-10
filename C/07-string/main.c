#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void getOneChar();
void getStringByScanf();
void getStringByGets();
void getStringByFgets();
void outPutString();
void getRandNumber();
void connectString();
void compareString();
int main() {

  char cont[] = "夏红";
  char *p = malloc(sizeof(cont));
  char *p2 = malloc(sizeof(cont));
  printf("cont length=%d sizeof(cont)=%d\n", strlen(cont), sizeof(cont));
  strcpy_s(p, strlen(cont)+1, cont);
  strcpy_s(p2, sizeof(cont), cont);
  printf("p=%s\n", p);
  printf("p2=%s\n", p2);

//  getOneChar();
//  getStringByScanf();
//  getStringByGets();
//  getStringByFgets();

//  outPutString();

//  connectString();

//  getRandNumber();

  compareString();
}
// 比较字符串
void compareString() {
  char str1[1024] = "";
  char str2[1024] = "";

  // 获取包括\n的字符串
  fgets(str1, sizeof(str1), stdin);
  fgets(str2, sizeof(str2), stdin);

  int str1len = strlen(str1);
  int str2len = strlen(str2);

  printf("strlen(str1)=%d\n", str1len);
  printf("strlen(str2)=%d\n", str2len);

  printf("str1[%d]=%d, %c\n", str1len, str1[str1len-1], str1[str1len-1]);
  printf("str2[%d]=%d, %c\n", str2len, str1[str2len-1], str2[str2len-1]);

  // 去掉 \n
  str1[str1len - 1] = '\0';
  str2[str2len - 1] = '\0';

  printf("str1[%d]=%d, %c\n", str1len, str1[str1len-1], str1[str1len-1]);
  printf("str2[%d]=%d, %c\n", str2len, str1[str2len-1], str2[str2len-1]);

  int i = 0;
//  while(str1[i] != 0 && str2[i] != 0) {
//    if (str1[i] != str2[i]) {
//      break;
//    }
//    i++;
//  }
  while(str1[i] != 0 && str2[i] != 0 && str1[i] == str2[i])i++;
  if (str1[i] < str2[i]) {
    printf("str1 < str2");
  } else if (str1[i] > str2[i]){
    printf("str1 > str2");
  } else {
    printf("str1 == str2");
  }
}
void connectString() {
  char num1[1024] = "hello";
  char num2[1024] = "world";

  printf("num1=%s\n", num1);
  printf("strlen(num1)=%d\n", strlen(num1));
  printf("strlen(num2)=%d\n", strlen(num2));

  int startIndex = strlen(num1);
  int num2EndIndex = strlen(num2);
  int i = 0;
  while(i < num2EndIndex) {
    num1[startIndex] = num2[i];
    startIndex++;
    i++;
  }

  printf("num1=%s\n", num1);
  printf("strlen(num1)=%d\n", strlen(num1));

}
void getRandNumber() {
  int t = time(NULL); // 获得当前时间 s
  srand(time(NULL)); // 设置随机种子数
  int a = rand(); // 随机数
  printf("a=%d\n", a);

  int b = rand(); // 随机数
  printf("a=%d\n", b);

}
void outPutString() {
  char buf[1024] = "hello world";

  puts(buf); // 数组首元素地址，有换行
  printf("abc\n");

  fputs(buf, stdout); // 没有换行
  printf("abc\n");

}

#define NUMBER 1024
void getStringByFgets() {
  char num[NUMBER];
  fgets(num, sizeof(num), stdin); // 从 std 读取字符串读取的num数组中, 最大可以读取sizeof(num) - 1 个字符
  printf("strlen(num)=%d\n", strlen(num)); // 4
//


//  if ((strlen(num) + 1) <= NUMBER) {
    num[strlen(num) - 1] = '\0'; // 去掉 \n
//  } else {
//    num[strlen(num)] = '\0'; // 去掉 \n
//  }




  printf("num=%s sizeof(num)=%d, strlen(num)=%d\n", num, sizeof(num), strlen(num));
}
void getStringByGets() {
  char num[5];
  gets(num);
  printf("num=%s\n", num);
}

// 从键盘获取一个字符串，遇到空白字符（\t \n 空格）结束
void getStringByScanf() {
  char num[6] = "";
  scanf("%s", num);

  // %s: 字符数组首元素地址
  // 存放读取字符的空间不足，继续向后存放造成内存污染
  printf("num=%s sizeof(num)=%d, strlen(num)=%d\n", num, sizeof(num), strlen(num));
}

// 从键盘获取一个字符
void getOneChar() {
  char ch = 0;
  char ch2 = 0;
  char ch3 = 0;
  scanf("%c", &ch);
  printf("ch=%c, %d\n", ch, ch);
  scanf("%c", &ch2);
  printf("ch2=%c, %d\n", ch2, ch2);
  scanf("%c", &ch3);
  printf("ch3=%c, %d\n", ch3, ch3);
}