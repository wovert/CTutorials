#include <iostream>

using namespace std;

class Drink {
public:
	Drink() {
		cout << "Drink 构造函数" << endl;
	}
	// 虚析构函数会调用子类的析构函数
	//virtual ~Drink() {
	//	cout << "Drink 析构函数" << endl;
	//}

	// 纯虚析构函数，抽象类，不能实例化对象
	// 需要在类外实现
	virtual ~Drink() = 0;
};
// 类外实现纯虚析构函数
Drink::~Drink() {
	cout << "纯虚析构函数 Drink" << endl;
}

class Coffee : public Drink {
public:
	Coffee() {
		cout << "Coffee 构造函数" << endl;
		pName = new char[64];
		memset(pName, 0, 64);
		strcpy_s(pName, 64, "咖啡");
	}
	~Coffee() {
		cout << "Coffee 析构函数" << endl;
		if (this->pName != NULL) {
			delete[] pName;
			pName = NULL;
		}
	}
public:
	char *pName;
};

class Tea : public Drink {
public:
	char *pName;
};

void demo02() {
	Drink *d = new Coffee;
	delete d;
}
int main() {
	demo02();
	return 0;
}