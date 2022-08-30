#define __cplushplus

#include <iostream>
using namespace std;

#include "math.h"
#include "math.h"
#include "math.h"
#include "math.h"

// 函数同时有声明和实现，函数声明被extern "C" 修饰
// 函数实现可以不修饰
void func(); // name mangling
extern "C" void func(int);
extern "C" void other();
double sum(double a, double b);

double sum(double a, double b) {
	return a + b;
}

void display(void);
void display(int);
void display(long);
void display(double);

void test04(void) {
	other();
	func();
	func(20);

	// 调用开源的C库
	cout << sum(10, 20) << endl;
	cout << delta(30, 3) << endl;
}


void test03() {
	// 逆向工程：IDA Pro
	display();
	display(1);
	display(10L);
	display(100.0);

	//test(10);
	//// 声明函数指针类型
	//void(*p)(int) = test;
	//p(100);

	//func(20, test);



}

void test02(void) {
	struct Date {
		int year;
		int month;
		int day;
	};
	Date d = { 1,2,3 };
	int array[] = { 1,2,3 };
	/*
	28: 	struct Date {
	29: 		int year;
	30: 		int month;
	31: 		int day;
	32: 	};
	33: 	Date d = { 1,2,3 };
002623E8  mov         dword ptr [ebp-10h],1
002623EF  mov         dword ptr [ebp-0Ch],2
002623F6  mov         dword ptr [ebp-8],3
	34: 	int array[] = { 1,2,3 };
002623FD  mov         dword ptr [ebp-24h],1
00262404  mov         dword ptr [ebp-20h],2
0026240B  mov         dword ptr [ebp-1Ch],3
	*/
}

// 代码本质挖掘
void test01() {
	// 编译时替换为4
	// 00842381  push        4
	cout << sizeof(int) << endl;
	cout << 4 << endl;
}

int main() {
	//test01();
	//test02();
	//test03();
	test04();

	// 等待键盘输入，按下回车键，就会读取键盘输入
	getchar();
	return 0;
}

void func() {

}

void func(int v) {
	printf("C语言方式编译 v=%d\n", v);
}
