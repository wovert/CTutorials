#include <iostream>
using namespace std;

class Maker {
public:
	Maker() {
		setCount();
	}
public:
	static void initCount() {
		count = 0;
	}
	static void setCount() {
		count++;
	}
	static int getCount() {
		return count;
	}
private:
	// 作用域在类内，生命周期在整个程序
	// 类内声明静态成员变量
	static int count;

	// const 修饰的静态成员变量最好在类内初始化
	const static int number = 100;
};

// 类外初始化静态成员变量，私有权限能定义且初始化
int Maker::count = 0;
const int number = 200;

void demo01() {
	// 初始化静态成员变量
	Maker::initCount();

	// 创建新的对象
	Maker m;

	// 所有对象共享
	//cout << m.count << endl;

	// 类访问静态成员变量
	cout << Maker::getCount() << endl;

	// 又创建新的对象
	Maker m2;

	// 访问类静态成员变量
	cout << Maker::getCount() << endl;
}

int main()
{
	demo01();
	return 0;
}