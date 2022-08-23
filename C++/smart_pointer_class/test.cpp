#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Maker {
public:
    string name;
    Maker() {
        name = "张三";
        cout << "无参构造" << endl;
    }
    ~Maker() {
        cout << "析构函数" << endl;
    }
    /**
     * @brief 仿函数作用：
     * 1. 方便代码维护
     * 2. 方便有权限的调用函数
     * 3. 作为算法的策略
     * 
     */
    void operator()() {
        cout << "无参仿函数" << endl;
    }
    void operator()(int v1, int v2) {
        cout << "有参仿函数" << endl;
    }
    void print() {
        cout << "Maker print method" << endl;
    }
};

class SmartPoint {
public:
    SmartPoint(Maker *m) {
        this->pMaker = m;
    }
    // 重载指针运算符
    Maker* operator->() {
        return this->pMaker;
    }
    // 重载星华
    Maker& operator*() {
        return *pMaker;
    }
    ~SmartPoint() {
        if (this->pMaker != NULL) {
            cout << "SmartPoint 析构函数" << endl;
            delete this->pMaker;
            this->pMaker = NULL;
        }
    }
private:
    Maker *pMaker;
};


void test01() {
    // 忘记delete
    Maker *p = new Maker;

    SmartPoint sm(p); // 栈区，调用析构函数
    sm->print();

    (*sm).print();
}

void test02() {
    Maker m;
    m();
    m(1, 2);
}

int main() {
    // test01();
    test02();
    system("pause");
    return 0;
}