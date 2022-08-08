#include <iostream>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

// 自定义数据类型，编译器不会优化
struct Maker {

	// 构造函数
	Maker() {
		a = 100;
	}
	int a;
};

const int gAge = 30;
int main() {

	int *gAgeP = (int *)&gAge;
	//*gAgeP = 2000; // 常量区不能修改
	cout << "gAgeP:" << *gAgeP << endl;
	
	// 禁止优化：使用age常量的区域不进行常量替换操作
	volatile const int age = 10;
	int *ageP = (int *)&age;
	*ageP = 1000;
	cout << "age:" << age << endl;
	cout << "*ageP:" << *ageP << endl;


	extern const int a;
	cout << "extern a:" << a << endl;

	int aa = 10;
	const int b = a; // 如果用变量给const 修饰的局部变量赋值，编译器不会优化
	int *pp = (int *)&b;
	*pp = 100;
	cout << "b=" << b << endl;
	cout << "*pp=" << *pp << endl;

	const Maker ma;
	cout << ma.a << endl; // 100
	Maker *maP = (Maker *)&ma;  
	maP->a = 200;
	cout << ma.a << endl; // 200, 没有优化，不能优化自定义数据类型

	// C
	// struct Date d = { 2022, 3, 8 };

	// C++ const 声明之后成员不能修改
	const Date d = { 2022, 3, 8 };
	
	// d.year = 2015;

	Date d1 = { 2011, 2, 5 };
	Date d2 = { 2013, 4, 8 };

	Date *p = &d1;
	p->year = 2015;

	// 变量修改成员属性
	(*p).month = 5;
	*p = d2;

	cout << d1.year << endl;

	const Date *p2 = &d1;
	// p2->year = 2015;
	// (*p2).month = 5;
	// *p2 = d2;


	// cout 是标砖的输出流对象，打印字符串
	// endl 是刷新缓冲区，并换行
	cout << d1.year << endl;

	getchar();
	return 0;
}