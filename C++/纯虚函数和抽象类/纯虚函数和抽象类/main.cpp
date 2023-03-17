#include <iostream>

using namespace std;


// 有纯虚函数的类叫抽象类，不能实例化对象
class Rule {
public:
	// 纯虚函数
	virtual int calc(int a, int b) = 0;
};

class RulePlus : public Rule {
public:
	// 重写父类的虚函数，依赖抽象层
	virtual int calc(int a, int b) {
		return a + b;
	}
};

class RuleMinus : public Rule {
public:
	// 重写父类的虚函数，依赖抽象层
	virtual int calc(int a, int b) {
		return a - b;
	}
};

int calc(Rule *r) {
	int a = 10;
	int b = 2;
	int result = r->calc(a, b);
	return result;
}

void test01() {
	Rule *r = NULL;
	r = new RulePlus;

	int result = calc(r); // 依赖抽象层
	cout << "result=" << result << endl;

	r = new RuleMinus;
	result = calc(r);
	cout << "result=" << result << endl;


	delete r;
}

int main() {
	test01();
	return 0;
}