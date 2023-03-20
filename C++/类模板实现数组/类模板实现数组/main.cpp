
#include <iostream>
#include <string>

#include "MyArray.hpp";


using namespace std;

class Maker {
public:
	Maker() { }
	Maker(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void print() {
		cout << "name=" << this->name << " age" << this->age << endl;
	}
public:
	string name;
	int age;
};

void printArray(MyArray<Maker> &arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		arr[i].print();
	}
}


void test01() {
	MyArray<Maker> myArr(4);
	Maker m1("悟空", 18);
	Maker m2("八戒", 28);
	Maker m3("萨省", 39);
	Maker m4("三张", 16);
	myArr.pushBack(m1);
	myArr.pushBack(m2);
	myArr.pushBack(m3);
	myArr.pushBack(m4);

	printArray(myArr);

}
int main() {
	test01();
	return 0;
}