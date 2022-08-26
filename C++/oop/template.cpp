#include <iostream>
using namespace std;

class Drink {
public:
    // 煮水
    virtual void Boil() = 0; // 接口的声明
    // 冲泡
    virtual void Brew() = 0;
    // 倒入杯中
    virtual void PourInCup() = 0; 
    // 加入辅料
    virtual void addSonm() = 0; 

    // 模板方法
    void func() {
        Boil();
        Brew();
        PourInCup();
        addSonm();
    }
};

class Coffee :public Drink {
public:
    // 接口的实现
    virtual void Boil() {
        cout << "煮点露水" << endl;
    }
    virtual void Brew() {
        cout << "拿铁" << endl;
    }
    virtual void PourInCup(){
        cout << "倒入杯中" << endl;
        
    }
    virtual void addSonm(){
        cout << "加糖" << endl;
    }
};

class Tea :public Drink {
public:
    // 接口的实现
    virtual void Boil() {
        cout << "煮点矿泉水" << endl;
    }
    virtual void Brew() {
        cout << "铁观音" << endl;
    }
    virtual void PourInCup(){
        cout << "倒入碗中" << endl;
        
    }
    virtual void addSonm(){
        cout << "不加任何" << endl;
    }
};

void test1(){
    Drink * d = NULL;
    d = new Coffee();
    d->func();

    d = new Tea();
    d->func();
}

int main() {
    test1();
    return 0;
}
