#include "MyString.h";
#include <iostream>
using namespace std;

MyString::~MyString() {
	if (this->pValue != NULL) {
		delete[] this->pValue;
		this->pValue = NULL;
	}
}
MyString::MyString() {
	// 申请堆空间
	this->pValue = new char[1];
	this->pValue[0] = '\0';
	this->mSize = 0;
}
MyString::MyString(int n, char c) {
	// 申请堆空间
	this->pValue = new char[n + 1];
	memset(this->pValue, 0, n + 1);
	for (int i = 0; i < n; i++) {
		this->pValue[i] = c;
	}
	this->pValue[n] = '\0';
	this->mSize = n;
}
MyString::MyString(const MyString &s) {
	this->pValue = new char[strlen(s.pValue) + 1];
	strcpy_s(this->pValue, strlen(s.pValue) + 1, s.pValue);
	this->mSize = s.mSize;
}


MyString &MyString::operator=(const MyString &s) {
	// 释放原来空间
	if (this->pValue != NULL) {
		delete[] this->pValue;
		this->pValue = NULL;
	}

	// 申请空间
	this->pValue = new char[strlen(s.pValue) + 1];

	// 拷贝数据
	strcpy_s(this->pValue, strlen(s.pValue) + 1, s.pValue);

	return *this;
}

MyString MyString::operator+(const MyString &s) {
	// MyString s3 = s1 + s2;
	// this s1, str s2
	
	// s3开辟的空间大小
	int newlen = this->mSize + s.mSize + 1;

	//cout << "newlen=" << newlen << endl;
	
	// 定义临时变量
	MyString temp;
	if (temp.pValue != NULL) {
		delete[] temp.pValue;
		temp.pValue = NULL;
	}

	// 申请新的空间
	temp.pValue = new char[newlen];
	memset(temp.pValue, 0, newlen);
	temp.mSize = this->mSize + s.mSize;

	//cout << "temp.mSize=" << temp.mSize << endl;

	// 追加字符到空间中
	strcat_s(temp.pValue, newlen, this->pValue);
	strcat_s(temp.pValue, newlen, s.pValue);
	//cout << "temp.pValue=" << temp.pValue << endl;

	return temp;
}

MyString MyString::operator+(const char *p) {

	//cout << "字符串p=" << p << ":" << strlen(p) << endl;
	int newlen = this->mSize + strlen(p) + 1;
	//cout << "newlen=" << newlen << endl;
	char *newSpace = new char[newlen + 1];
	// 开辟空间
	memset(newSpace, 0, newlen + 1);


	//追加数据到空间
	strcat_s(newSpace, newlen, this->pValue);

	//cout << "newSpace1=" << newSpace << endl;

	strcat_s(newSpace, newlen, p);

	//cout << "newSpace2=" << newSpace << endl;

	MyString temp;
	if (temp.pValue != NULL) {
		delete[] temp.pValue;
		temp.pValue = NULL;
	}
	temp.pValue = newSpace;
	temp.mSize = newlen;
	return temp;
}

MyString &MyString::operator+=(const MyString &s) {
	// 获取两个字符串的总字符个数
	int newlen = this->mSize + s.mSize;

	// 申请新空间
	char *newSpace = new char[newlen + 1];
	memset(newSpace, 0, newlen + 1);

	// 追加数据
	strcat_s(newSpace, newlen + 1, this->pValue);
	strcat_s(newSpace, newlen + 1, s.pValue);

	// 释放本身的空间
	if (this->pValue != NULL) {
		delete[] this->pValue;
		this->pValue = NULL;
	}

	this->pValue = newSpace;
	this->mSize = newlen;

	return *this;
}

MyString &MyString::operator+=(const char *p) {
	// 获取两个字符串的总字符个数
	int newlen = this->mSize + strlen(p);

	// 申请新空间
	char *newSpace = new char[newlen + 1];
	memset(newSpace, 0, newlen + 1);

	// 追加数据
	strcat_s(newSpace, newlen + 1, this->pValue);
	strcat_s(newSpace, newlen + 1, p);

	// 释放本身的空间
	if (this->pValue != NULL) {
		delete[] this->pValue;
		this->pValue = NULL;
	}

	this->pValue = newSpace;
	this->mSize = newlen;

	return *this;
}

int MyString::size() {
	return this->mSize;
}

char &MyString::operator[](int index) {
	return this->pValue[index];
}
ostream &operator<<(ostream &out, MyString &s) {
	out << s.pValue;
	return out;
}
istream &operator>>(istream &in, MyString &s) {
	//cin >> s4;
	// 用户输入的的字符串存储到s4.pValue指向的堆区空间
	char temp[1024] = { 0 };
	// 获取用户输入的信息

	in >> temp;

	// 释放s4空间
	if (s.pValue != NULL) {
		delete[] s.pValue;
	}

	// 申请新的空间
	s.pValue = new char[strlen(temp) + 1];
	memset(s.pValue, 0, strlen(temp) + 1);

	// 拷贝用户输入的信息到堆区空间
	strcpy_s(s.pValue, strlen(temp) + 1, temp);
	s.mSize = strlen(temp);
	
	return in;
}