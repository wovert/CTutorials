#include <iostream>

using namespace std;

int swap(int a, int b) {
	int result = a + b;
	return result;
}

template<typename T>
int swap2(T a, T b) {
	T result = a + b;
	return result;
}

//template <class T>
template <typename T>
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}


void  test01() {
	int a = 10;
	int b = 20;
	char c = 'a';
	cout << "a=" << a << ", b=" << b << endl;
	// 编译器函数模板被调用时，进行第二次编译
	mySwap<int>(a, b);
	cout << "a=" << a << ", b=" << b << endl;

	// 普通函数与函数模板区别: 普通函数可以隐式转换
	cout << "a + c = " << swap(a, c) << endl;

	// 普通函数与函数模板区别: 函数模板不可以隐式转换
	cout << "a + c = " << swap2<int>(a, c) << endl;


}
int main() {
	test01();
	return 0;
}