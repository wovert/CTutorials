#ifndef __MYARRAY_H__
#define __MYARRAY_H__

class MyArray {
private:
    int capacity; // 总量
    int size; // 元素个数
    int *addr; // 首元素地址
public:
    MyArray();
    MyArray(int capacity);
    ~MyArray();

    void pushBack(int data);
    int getData(int pos);
    void setData(int pos, int data);
    int getCapacity(void);
    int getSize(void);
    int operator[](int index);
};


#endif