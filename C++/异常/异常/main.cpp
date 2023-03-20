#include <iostream>
#include <string>

using namespace std;

int print(int arr[], int len) {
	if (arr == NULL) {
		return -1;
	}
	if (len == 0) {
		return 0;
	}
}

// 只允许抛出 int 异常
int func(int a, int b) throw(int) { 
	if (b == 0) {
		throw 10;
	}
	return a / b;
}

void test() {
	int a = 10;
	int b = 0;

	try {
		func(a, b);
	}
	catch (int) {
		cout << "接受一个int类型的异常" << endl;
	}
	catch (...) {
		cout << "接受一个其他类型的异常" << endl;
	}
}

int main() {
	int *arr = NULL;
	int len = 0;
	print(arr, len);
	test();
	return 0;
}