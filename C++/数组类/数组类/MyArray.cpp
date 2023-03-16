#include "MyArray.h";
#include <iostream>
using namespace std;


MyArray::~MyArray() {
	if (this->pArray != NULL) {
		delete this->pArray;
		this->pArray = NULL;
	}
}

MyArray::MyArray() {
	this->mCapacity = 20;
	this->mSize = 0;
	this->pArray = new int[this->mCapacity];
	for (int i = 0; i < this->mCapacity; i++) {
		this->pArray[i] = 0;
	}
}

// int val: 元素默认值
MyArray::MyArray(int capacity, int val) {
	this->mCapacity = capacity;
	this->mSize = capacity;
	this->pArray = new int[capacity];
	for (int i = 0; i < this->mSize; i++) {
		this->pArray[i] = val;
	}
}

MyArray::MyArray(const MyArray &arr) {
	this->mCapacity = arr.mCapacity;
	this->mSize = arr.mSize;
	// 申请空间
	this->pArray = new int[arr.mCapacity];
	// 拷贝数据
	for (int i = 0; i < this->mSize; i++) {
		this->pArray[i] = arr.pArray[i];
	}

}


void MyArray::pushFront(int val) {
	 // 判断容量是否满
	if (this->mSize == this->mCapacity) {
		return;
	}
	for (int i = this->mSize - 1; i >= 0; i--) {
		this->pArray[i + 1] = this->pArray[i];
	}
	// 空出0的位置
	this->pArray[0] = val;
	this->mSize++;
}

void MyArray::pushBack(int val) {
	// 判断容量是否满
	if (this->mSize == this->mCapacity) {
		return;
	}
	this->pArray[this->mSize] = val;
	this->mSize++;
}

void MyArray::popFront() {
	if (this->mSize == 0) {
		return;
	}
	for (int i = 0; i < this->mSize - 1; i++) {
		this->pArray[i] = this->pArray[i+1];
	}
	this->pArray[this->mSize-1] = 0;
	this->mSize--;
}
void MyArray::popBack() {
	if (this->mSize == 0) {
		return;
	}
	this->pArray[this->mSize-1] = 0;
	this->mSize--;
}
int MyArray::size() {
	return this->mSize;
}
int MyArray::capacity() {
	return this->mCapacity;
}
void MyArray::insert(int pos, int val) {
	// 判断容量是否满
	if (this->mSize == this->mCapacity) {
		return;
	}
	// 位置不对，插入尾部
	if (pos < 0 || pos > this->mSize - 1) {
		pos = this->mSize;
	}
	for (int i = this->mSize - 1; i >= pos; i--) {
		this->pArray[i + 1] = this->pArray[i];
	}
	// pos 位置空置
	this->pArray[pos] = val;
	this->mSize++;
}

// 获取指定位置的值
int &MyArray::get(int pos) {
	return this->pArray[pos];
}

void MyArray::set(int pos, int val) {
	if (pos <= 0 || pos > this->mCapacity - 1) {
		return;
	}
	this->pArray[pos] = val;
}



MyArray &MyArray::operator=(const MyArray &m) {
	cout << "MyArray=>>>" << endl;
	// 释放原来的空间
	if (this->pArray != NULL) {
		delete[] this->pArray;
		this->pArray = NULL;
	}
	this->mCapacity = m.mCapacity;
	this->mSize = m.mSize;
	
	// 申请空间
	this->pArray = new int[m.mSize];
	
	// 拷贝数据
	for (int i = 0; i < this->mSize; i++) {
		this->pArray[i] = m.pArray[i];
	}
	return *this;
}

// 要能当左右值
int &MyArray::operator[](int index) {
	cout << "MyArray[]>>>" << endl;
/*	if (this->mSize <= index) {
		this->mSize++;
	}*/
	return this->pArray[index];
}