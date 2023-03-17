#include <iostream>

using namespace std;

class Animal {
public:
	Animal() {
		mA = 100;
	}
public:
	int mA;
};

// 用虚继承解决棱形继承中的二义性问题
class Sheep:virtual public Animal {

};
class Camel:virtual public Animal {

};

class SheepCamel :public Sheep, public Camel {

};

void demo01() {
	SheepCamel sc;
	// 有二义性
	cout << sc.mA << endl;
}
void demo02() {
	Sheep s;
	//s.mA;

	// 1. &a
	// 2. (int *)&s, 强转为 int * 类型
	// 3. *(int *)&s 获取指针中的地址
	// 4. (int *)*(int *)&s 指向了表的首地址
	// 5. (int *)*(int *)&s + 1 指向了表存储偏移量的地址
	// 6. *((int *)*(int *)&s + 1) 这就是偏移量

	cout << *((int *)*(int *)&s + 1) << endl;

	// 1. *s
	// 2. (char *)&s;
	// 3. (char *)&s + *((int *)*(int *)&s + 1);
	// 4. 类型转换为 Animal 指针类型 
	cout << ((Animal *)((char *)&s + *((int *)*(int *)&s + 1)))->mA << endl;


	Camel c;

	cout << *((int *)*(int *)&c + 1) << endl;
	cout << ((Animal *)((char *)&c + *((int *)*(int *)&c + 1)))->mA << endl;

}

int main() {
	//demo01();
	demo02();
	return 0;
}