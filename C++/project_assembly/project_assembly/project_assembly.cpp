#include <iostream>
using namespace std;


void test(){
	int a = 5;
	int b = 10;
	int c = a + b;
}
void func() {}

int main() {
	test();
	func();
	int a = 5;
	int b = 10;
	int c = a + b;

	// arr数组的地址，也是数组首元素的地址
	// arr指向数组首元素的指针 int *
	int arr[] = { 1,2,3 };

	// 1.数组的引用
	int (&ref)[3] = arr;

	// 2.数组的引用
	// arr = int *
	// 数组名arr是常量，常引用才能引用常量
	int * const &ref2 = arr;
	ref2[0] = 1000;
	cout << ref2[0] << endl;

	getchar();
	return 0;
}
