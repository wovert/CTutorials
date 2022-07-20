#include <iostream>
using namespace std;

void display() {
	cout << "display() " << endl;
}

void display(int i) {
	cout << "display(int) " << i << endl;
}

void display(long i) {
	cout << "display(long) " << i << endl;
}

void display(double i) {
	cout << "display(double) " << i << endl;
}

void test(int a) {
	cout << "test(int) " << a << endl;
}

// 默认参数
void func(int v1=2039, void(*p)(int)=test) {
	p(v1);
}

int sum(int v1, int v2=2) {
	return v1 + v2;
}

// 逆向工程：IDA Pro
int main() {

	sum(1);
	// sum(5, 6);
	return 0;

	test(10);
	// 声明函数指针类型
	void(*p)(int) = test;
	p(100);

	func(20, test);

	display();
	display(1);
	display(10L);
	display(100.0);
	return 0;
}