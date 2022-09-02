#include <iostream>
#include <string.h> // memset
#include <stdlib.h> // malloc

using namespace std;

void test01() {
    int *p = (int *) malloc(4);
    *p = 10;
    free(p);

    char *pChar = (char *) malloc(4);
    memset(p, '#', sizeof(pChar));
    cout << pChar << endl; // ####

    *pChar = 10; // 存储一个字节
    *(pChar + 1) = 20;
    *(pChar + 2) = 30;
    *(pChar + 3) = 40;
    cout << pChar << endl;

    pChar[0] = 10;
    pChar[1] = 10;
    pChar[2] = 10;
    pChar[3] = 10;

    free(pChar); // 释放4个字节
}

void test02(void) {
    int *pi1 = (int *)malloc(sizeof(int)); // *p1 未初始化
    int *pi2 = (int *)malloc(sizeof(int));
    memset(pi2, 0, sizeof(int)); // 将*p2的每一个字节都初始化为0

    int *p1 = new int; // 未初始化
    int *p2 = new int(); // 被初始化0
    int *p3 = new int(5); // 被初始化5
    int *p4 = new int[3]; // 数组元素未被初始化
    int *p5 = new int[3](); // 3个数组元素被初始化0
    int *p6 = new int[3]{}; // 3个数组元素被初始化0
    int *p7 = new int[3]{5}; // 数组首元素被初始化为5， 其他元素被初始化为0

    memset(p2, 0, sizeof(p2));
    memset(p7, 0, sizeof(p7));

}

int main() {
    test01();
    test02();
    return 0;
}