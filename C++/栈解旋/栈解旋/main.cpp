#include <iostream>
#include <string>

using namespace std;

class Maker {
public:
	Maker() {
		cout << "Maker的构造" << endl;
	}
	Maker(const Maker &m) {
		cout << "Maker的拷贝构造" << endl;
	}
	~Maker() {
		cout << "Maker析构" << endl;
	}
};

void func() {
	//Maker m; // 第一个对象
	//throw m; // Maker 拷贝的 // 第二个对象

	// 编译器不允许栈中的匿名对象取地址操作
	//throw Maker();
	// 编译器允许对堆区中的匿名对象取地址操作
	throw new Maker();

	cout << "func函数结束" << endl;
}

void test() {
	try {
		func();
		cout << "func函数结束的代码" << endl;
	}
	// 第三个对象
	//catch (Maker &m) {
	catch (Maker *m) {
		cout << "接受一个Maker类型的异常" << endl;
		delete m;
	}
}

int main() {
	test();
	return 0;
}