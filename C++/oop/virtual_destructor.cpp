#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Parent {
public:
    Parent() {
        cout << "Parent 的构造函数" << endl;
    }
    // 虚析构函数会调用子类的虚构函数
    // virtual ~Parent() {
    //     cout << "Parent 的析构函数" << endl;
    // }
    // 纯虚析构函数，需要在类外实现
    // 不能实例化对象
    virtual ~Parent() = 0;
};
Parent::~Parent() {
    cout << "Parent 的纯虚析构函数" << endl;
}


class Child :public Parent {
public:
    char *pName;
public:
    Child() {
        cout << "Child 的构造函数" << endl;
        pName = new char[64];
        memset(pName, 0, 64);
        strcpy(pName, "张三");
    }
    ~Child() {
        cout << "Child 的析构函数" << endl;
        if (pName != NULL) {
            delete [] pName;
            pName = NULL;
        }
    }
};

void test1(){
    Parent *p = new Child();
    delete p;
}

int main() {
    test1();
    return 0;
}
