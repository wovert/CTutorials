#include <iostream>
#include <string>
using namespace std;


template<class NameType, class AgeType>
class Maker;


// 友元在类外实现函数模板
template<class NameType, class AgeType>
void getMakerInfo(Maker<NameType, AgeType> &m) {
	cout << "name=" << m.name << ", age=" << m.age << endl;
}

template<class NameType, class AgeType>
class Maker {
	friend void getMakerInfo<>(Maker<NameType, AgeType> &m);
public:
	Maker(NameType name, AgeType age);
	void print();
private:
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


