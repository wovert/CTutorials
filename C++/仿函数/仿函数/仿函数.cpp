#include <string>
#include <iostream>
using namespace std;

class Maker {
public:
	Maker() {
		name = "张三";
	}
	void print() {
		cout << "name=" << name << endl;
	}

	void operator()(int v1, int v2) {
		cout << "() ----" << v1 << v2 << endl;
	}
public:
	string name;
};

int main()
{
	Maker m;

	// 仿函数
	m(10, 20); // 调用重载()函数
	return 0;
}
