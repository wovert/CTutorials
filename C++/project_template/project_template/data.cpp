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

// const ���γ�Ա���������������޸���ͨ��Ա����������mutable �����ĳ�Ա����
void Data::getInfo() const {
	mnum = 123;
	cout << "const function" << endl;
	cout << "mnum=" << mnum << endl;
}
void Data::envNum() const {
	cout << "const function" << endl;
}

int Data::shareData = 100; // ��̬��Ա�������ⶨ��+��ʼ��
const int Data::onlyData = 10000; // ���ⶨ��+��ʼ��