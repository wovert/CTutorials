#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "add.h"

// 宏：编译时替换
#define RKVIR 1

void array();
void doubleTest();


// extern 告诉编译器该函数来自于其他文件(extern 声明函数外部可用)
extern void disBin(char ch);
extern void testFloat();
extern void testFunc();
extern void testPoint();
extern void testDefine();
extern void testSort();
extern void testArray();
extern void testFuncPointer();
extern void testMalloc();
extern void testStrFunc();

void demo() {
	int a = 3;
	int b = 10;
	int c = a + b;
	printf("c=%d\n", c);
}

void test() {
	// 只读变量
	const int a = 1;
	printf("%d", RKVIR);
	int result = add(10, 30);
	printf("result=%d\n", result);

	_Bool flag = true;
	if (flag) {
		printf("Flag is true\n");
	}
}

void testDisBin() {

	char a = 0;
	disBin(a);
	char b = 1;
	disBin(b);
	char c = 2;
	disBin(c);
	char d = 127;
	disBin(d);
	char e = -128;
	disBin(e);
	char f = -2;
	disBin(f);
	char g = -1;
	disBin(g);
	printf("----------------\n");
	for (char i = -128; i < 128; i++) {
		disBin(i);
		if (i == 127) break;
	}

}



int main() {
	 //testFunc();

	// demo();
	// test();
	// array();

	// doubleTest();
	// testDisBin();
	//testFloat();
	//testPoint();
	//testDefine();
	//testSort();
	//testArray();

	//testFuncPointer();

	//testMalloc();
	testStrFunc();
	system("pause");
	return 0;
}