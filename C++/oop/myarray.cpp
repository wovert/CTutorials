#include "myarray.h"
#include <iostream>
using namespace std;


// 定义无参构造函数
MyArray::MyArray() {
    this->capacity = 100;
    this->size = 0;
    // 根据容量给数组申请空间
    this->addr = new int[this->capacity];
}

MyArray::MyArray(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    // 根据容量给数组申请空间
    this->addr = new int[this->capacity];  
}
MyArray::~MyArray() {
    if (this->addr != NULL) {
        delete [] this->addr;
        this->addr = NULL;
    }
}
void MyArray::pushBack(int data) {
    if (this->size >= this->capacity) {
        cout << "array is full" << endl;
        return;
    }
    this->addr[this->size] = data;
    this->size++;
}

int MyArray::getData(int pos) {
    if (pos >= this->size || pos < 0) {
        cout << "Not found position:" << pos << endl;
        return -1;
    }
    return addr[pos];
}

void MyArray::setData(int pos, int data) {
    if (pos >= this->size || pos < 0) {
        cout << "Not found position:" << pos << endl;
        return;
    }
    this->addr[pos] = data;
}
int MyArray::getCapacity(void) {
    return this->capacity;
}
int MyArray::getSize(void) {
    return this->size;
}

