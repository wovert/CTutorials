#include <iostream>

using namespace std;

inline int sum();

// 开辟
inline int sum(int a, int b) {
	return a + b;
}

// 普通函数：开辟栈空间
int normalFunc(int a, int b) {
	return a + b;
}
// 回收栈空间

int main(int argc, char *argv[])
{
	// 调用函数开辟内存空间
	int result = normalFunc(10, 20);

	cout << "result=" << result << endl;

	// 编译器此处替换函数代码，不存在函数调用 代码变为 int c = 20 + 40;
	// 1.用于函数代码体积不大
	// 2.频繁调用函数是使用inline
	int c = sum(10, 20);

	cout << "c=" << c << endl;

	cout << "----------" << endl;
	int a = 1;
	int b = 2;
	(a = b) = 4;
	cout << "a=" << a << endl; // 4
	cout << "b=" << b << endl; // 2

	(a > b ? a : b) = 4;
	cout << "a=" << a << endl; // 4
	cout << "b=" << b << endl; // 2

	return 0;
}
