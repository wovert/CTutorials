#include "data.h"

void Data::setNum(int n) {
	num = n;
}
int Data::getNum(void) {
	return num;
}

void Data::setAge(int n) {
	age = n;
}
int Data::getAge(void) {
	return age;
}
void Data::setName(char *name) {
	this->name = name;
}
char * Data::getName(void) {
	return this->name;
}

// const 修饰成员变量，函数不能修改普通成员变量，除了mutable 声明的成员变量
void Data::getInfo() const {
	mnum = 123;
	cout << "const function" << endl;
	cout << "mnum=" << mnum << endl;
}
void Data::envNum() const {
	cout << "const function" << endl;
}

int Data::shareData = 100; // 静态成员变量类外定义+初始化
const int Data::onlyData = 10000; // 类外定义+初始化