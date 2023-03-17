#include <iostream>
#include <string>

using namespace std;


class Father {
public:
	Father() {
		cout << "Father 无参构造函数" << endl;
	}
	~Father() {
		cout << "Father 析构函数" << endl;
	}
	void funcA() {
		cout << "Fater的公有属性成员a=" << a << endl;
	}
	void funcA(int aa) {
		cout << "Fater 形参aa=" << aa << endl;
		cout << "Fater的公有属性成员a=" << a << endl;
	}
	void func1() {
		cout << "父亲 func1" << endl;
	}
	void func2() {
		cout << "父亲 func2" << endl;
	}
public:
	int a = 1;
protected:
	int b = 2;
private:
	int c = 3;
};

class Car {
public:
	Car() {
		cout << "Car 无参构造函数" << endl;
	}
	~Car() {
		cout << "Car 析构函数" << endl;
	}
};


// 公有继承
class Son : public Father {
public:
	int a = 10000; // 子类同名的成员属性隐藏父类的同名成员
private:
	int s1 = 10;
	int s2 = 20;
	Car c;
public:
	Son() {
		cout << "Son 无参构造函数" << endl;
	}
	~Son() {
		cout << "Son 析构函数" << endl;
	}
	void func3() {
		cout << "儿子 func3" << endl;
	}
	void funcA() {
		cout << "Son的公有属性成员a=" << a << endl;
	}
	void funcB() {
		cout << "Fater的保护属性成员b=" << b << endl;
	}
	void funcC() {
		// 不能访问私有成员变量
		//cout << "Fater.c=" << c << endl;
	}
};

// 保护继承
class Daughter : protected Father {
public:
	void funcA() {
		cout << "Fater的公有属性成员a=" << a << endl;
	}
	void funcB() {
		cout << "Fater的保护属性成员b=" << b << endl;
	}
	void funcC() {
		// 不能访问私有成员变量
		//cout << "Fater.c=" << c << endl;
	}
};

// 私有继承
class Son2 : protected Father {
public:
	void funcA() {
		cout << "Fater的公有属性成员a=" << a << endl;
	}
	void funcB() {
		cout << "Fater的保护属性成员b=" << b << endl;
	}
	void funcC() {
		// 不能访问私有成员变量
		//cout << "Fater.c=" << c << endl;
	}
};

void demo01() {
	Son s;
	s.func1();
	s.func2();
	s.func3();
	s.funcA();
	s.funcB();
	s.funcC();
	cout << "_______________" << endl;
	Daughter d;
	d.funcA();
	//cout << d.a << endl;
	d.funcB();
	d.funcC();
	cout << "_______________" << endl;

	Son s2;
	s2.funcA();
	s2.funcB();
	s2.funcC();
}

void demo02() {
	Son s;

	// 子类同名的成员属性隐藏父类的同名成员
	cout << s.a << endl;

	// 通过父类名加作用域访问父类的成员属性
	cout << s.Father::a << endl;
}
void demo03() {
	Son s;
	s.funcA();
	//s.funcA(30); // 父类所有函数重载都会被隐藏
	s.Father::funcA(30);
}

int main() {
	//demo01();
	//demo02();
	demo03();

	return 0;
}