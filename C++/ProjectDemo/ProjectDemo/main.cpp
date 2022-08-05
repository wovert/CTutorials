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

int main() {
	other();
	func();
	func(20);
	
	// 调用开源的C库
	cout << sum(10, 20) << endl;
	cout << delta(30, 3) << endl;

	getchar();
	return 0;
}

void func() {

}

void func(int v) {

}
