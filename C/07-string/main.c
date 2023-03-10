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

  char cont[] = "�ĺ�";
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
// �Ƚ��ַ���
void compareString() {
  char str1[1024] = "";
  char str2[1024] = "";

  // ��ȡ����\n���ַ���
  fgets(str1, sizeof(str1), stdin);
  fgets(str2, sizeof(str2), stdin);

  int str1len = strlen(str1);
  int str2len = strlen(str2);

  printf("strlen(str1)=%d\n", str1len);
  printf("strlen(str2)=%d\n", str2len);

  printf("str1[%d]=%d, %c\n", str1len, str1[str1len-1], str1[str1len-1]);
  printf("str2[%d]=%d, %c\n", str2len, str1[str2len-1], str2[str2len-1]);

  // ȥ�� \n
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
  int t = time(NULL); // ��õ�ǰʱ�� s
  srand(time(NULL)); // �������������
  int a = rand(); // �����
  printf("a=%d\n", a);

  int b = rand(); // �����
  printf("a=%d\n", b);

}
void outPutString() {
  char buf[1024] = "hello world";

  puts(buf); // ������Ԫ�ص�ַ���л���
  printf("abc\n");

  fputs(buf, stdout); // û�л���
  printf("abc\n");

}

#define NUMBER 1024
void getStringByFgets() {
  char num[NUMBER];
  fgets(num, sizeof(num), stdin); // �� std ��ȡ�ַ�����ȡ��num������, �����Զ�ȡsizeof(num) - 1 ���ַ�
  printf("strlen(num)=%d\n", strlen(num)); // 4
//


//  if ((strlen(num) + 1) <= NUMBER) {
    num[strlen(num) - 1] = '\0'; // ȥ�� \n
//  } else {
//    num[strlen(num)] = '\0'; // ȥ�� \n
//  }




  printf("num=%s sizeof(num)=%d, strlen(num)=%d\n", num, sizeof(num), strlen(num));
}
void getStringByGets() {
  char num[5];
  gets(num);
  printf("num=%s\n", num);
}

// �Ӽ��̻�ȡһ���ַ����������հ��ַ���\t \n �ո񣩽���
void getStringByScanf() {
  char num[6] = "";
  scanf("%s", num);

  // %s: �ַ�������Ԫ�ص�ַ
  // ��Ŷ�ȡ�ַ��Ŀռ䲻�㣬�������������ڴ���Ⱦ
  printf("num=%s sizeof(num)=%d, strlen(num)=%d\n", num, sizeof(num), strlen(num));
}

// �Ӽ��̻�ȡһ���ַ�
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