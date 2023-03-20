#include <iostream>
#include <string>

using namespace std;

template<class T>
class Father {
public:
	Father() {
		m = 20;
	}
public:
	T m;
};

// 普通类
// 告诉编译器父类的泛型数据类型具体是什么类型
class Son : public Father<int> {

};


// 类模板
// 告诉编译器父类的泛型数据类型具体是什么类型
template<class T1, class T2>
class Daughter : public Father<T2> {

};

void test01() {
	Daughter<int, int> d;
	cout << d.m << endl;
}


int main() {
	test01();
	return 0;
}
