#include <iostream>

using namespace std;

class Single {
private:
	Single() {
		cout << "Single 构造函数" << endl;
	}
	Single(const Single &s) {
		cout << "Single 拷贝函数" << endl;
	
	}
public:
	~Single() {
		cout << "Single 析构函数" << endl;
	}
public:
	// 静态成员指针
	static Single *single;

	int a;

	// 静态成员函数
	static Single *getSingle() {
		return single;
	}
};

// 类外初始化静态成员变量
// new 在 Single:: 作用域，编译器这时把它当成在类内
// 写法在类外
Single *Single::single = new Single();

// 报错 下面代码执行时，还没有分配空间，所以不能赋值
//int Single::a = 20;


int main()
{
	Single *single1 = Single::getSingle();
	//Single single2 = *single1;
	Single *single3 = Single::getSingle();
	Single *single4 = Single::getSingle();

	delete single1;
	return 0;
}