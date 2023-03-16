#include <iostream>
#include <string>

using namespace std;

// 声明类
class Building;

// 类的成员函数成为的类的友元函数
class GoodGay {
public:
	void func(Building &bud);
};


class Building {
	// 声明全局函数为Building类的友元函数，不是类的成员函数
	friend void GoodBuy(Building &bd);

	// 声明Group类为友元类
	friend class Group;
	friend class Root;

	// 类的成员函数成为的类的友元函数
	// 编译器知道类的声明，不知道类的结构
	friend void GoodGay::func(Building &bud);

public:
	Building() {
		keting = "客厅";
		woshi = "卧室";
	}
public:
	string keting;
private:
	string woshi;
};

class Group {
public:
	void func(Building &bd) {
		cout << "访问" << bd.keting << endl;
		cout << "访问" << bd.woshi << endl;
	}
};

// 通过类内指针访问类的私有成员
class Root {
public:
	Building *pB;
public:
	Root() {
		pB = new Building;
	}
	Root(const Root &r) {
		// 申请空间
		pB = new Building;
	}
	~Root() {
		if (pB != NULL) {
			delete pB;
		}
	}
	void func() {
		cout << "访问" << pB->keting << endl;
		cout << "访问" << pB->woshi << endl;
	}
};


// 实现函数
void GoodGay::func(Building &bud) {
	cout << "访问" << bud.keting << endl;
	cout << "访问" << bud.woshi << endl;
}


void GoodBuy(Building &bd) {
	cout << "好基友访问: " << bd.keting << endl;
	cout << "好基友访问: " << bd.woshi << endl;
}

void demo01() {
	Building b;
	GoodBuy(b);
}

void demo02() {
	Building b;
	Group g;
	g.func(b);
}

void demo03() {
	Root r;
	r.func();

	Root r2 = r;
}

void demo04() {
	Building b;
	GoodGay gb;
	gb.func(b);
}

int main()
{
	//demo01();
	//demo02();
	//demo03();
	demo04();
	return 0;
}