#pragma once
#include <iostream>

using namespace std;

class MyString {
	friend ostream &operator<<(ostream &out, MyString &s);
	friend istream &operator>>(istream &in, MyString &s);

public:
	MyString();
	MyString(int n, char c); // 初始化n个c字符组成的字符串
	MyString(const MyString &s);
	~MyString();

	MyString &operator=(const MyString &s);
	MyString operator+(const MyString &s);
	MyString operator+(const char *p);

	MyString &operator+=(const MyString &s);
	MyString &operator+=(const char *p);

	int size();

	char &operator[](int index);

private:
	char *pValue; // 指向堆区空间
	int mSize;
};