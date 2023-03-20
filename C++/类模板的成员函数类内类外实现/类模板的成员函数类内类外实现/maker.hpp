#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType>
class Maker {
public:
	Maker(NameType name, AgeType age);
	void print();
public:
	NameType name;
	AgeType age;
};

// 类模板成员函数类外实现
template<class NameType, class AgeType>
Maker<NameType, AgeType>::Maker(NameType name, AgeType age) {
	this->name = name;
	this->age = age;
}

template<class NameType, class AgeType>
void Maker<NameType, AgeType>::print() {
	cout << "Name:" << name << " Age:" << age << endl;
}