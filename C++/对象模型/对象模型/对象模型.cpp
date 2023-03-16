#include <iostream>
using namespace std;

class Maker {
	//void func(Maker *this) {
	void func() {
		cout << "成员函数" << endl;
	}

	// 返回对象本身 & 引用
	Maker &getMaker() {
		return *this; // this 指针的指向不能改变，this是Maker * const this
	}
	static int a;
	static void staticFunc() {

	}
	int number;
};

int Maker::a = 20;

int main()
{
	cout << sizeof(Maker) << endl;
	Maker *m = new Maker[20]; // 空类是1， 编译器从内存更好的区分对象
	return 0;
}
