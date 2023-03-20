#include <iostream>

using namespace std;


// 静态转换
void  test01() {
	char a = 'a';

	// 基础类型转换
	double d = static_cast<double>(a);
	double d1 = (double)a;
}

class Father {

};

class Son : public Father {

};

class Other {};

// 层次关系类的指针或引用转换
void test02() {
	Father *f = NULL;
	Son *s = NULL;

	// 向下转换，不安全
	Son *s1 = static_cast<Son*>(f);

	// 向上转换，安全
	Father *f1 = static_cast<Father*>(s);

}

void test03() {
	Father f;
	Son s;

	Father &ref_f = f;
	Son &ref_s = s;

	// 子类引用转换父类，安全
	static_cast<Father &>(ref_s);

	// 向下转换，不安全
	static_cast<Son &>(ref_f);
}

// 动态转换(主要用于层次见的上下转换): 与静态转换类似，区别是向下转换时报错
void test04() {

}

void test05() {
	const int *p = NULL;
	// const 转 不带 const
	// 常量指针被转化成非常量指针，并且任然指向原来的对象
	int *newP = const_cast<int*>(p);

	// 常量引用被转化成非常量引用，并且任然指向原来的对象

	int **pp = NULL;
	//const int* newPP = const_cast<const int*>(pp);

}

// 重新解释转换
void test06() {
	int a = 10;
	int *p = reinterpret_cast<int *>(a);

	Father *f = NULL;
	Other *o = reinterpret_cast<Other *>(f);


}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();

	return 0;
}