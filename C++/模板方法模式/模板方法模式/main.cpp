#include <iostream>

using namespace std;

class Drink {
public:
	Drink() {
		cout << "Drink 构造函数" << endl;
	}
	~Drink() {
		cout << "Drink 析构函数" << endl;
	}
	virtual void Boil() = 0; // 煮水
	virtual void Brew() = 0; // 冲泡
	virtual void PourInCup() = 0; // 导入杯中
	virtual void AddSonm() = 0; // 加点辅料

	// 模板方法
	void func() {
		Boil();
		Brew();
		PourInCup();
		AddSonm();
	}
};

class Coffee : public Drink {
public:
	virtual void Boil() {
		cout << "煮点热水" << endl;
	}
	virtual void Brew() {
		cout << "拿铁" << endl;
	}
	virtual void PourInCup() {
		cout << "倒入咖啡杯中" << endl;
	}
	virtual void AddSonm() {
		cout << "加点糖" << endl;
	}
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
	virtual void Boil() {
		cout << "煮点自来水" << endl;
	}
	virtual void Brew() {
		cout << "铁观音" << endl;
	}
	virtual void PourInCup() {
		cout << "倒入茶杯中" << endl;
	}
	virtual void AddSonm() {
		cout << "不加任何..." << endl;
	}
public:
	char *pName;
};


void demo01() {
	Drink *d = NULL;
	d = new Coffee;
	d->func();

	d = new Tea;
	d->func();
	
	delete d;
	d = NULL;
}
void demo02() {
	Drink *d = new Coffee;
	delete d; // 缺少子类的析构函数
}
int main() {
	//demo01();
	demo02();
	return 0;
}