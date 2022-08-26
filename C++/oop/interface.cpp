#include <iostream>
using namespace std;

class Father {
public:
    virtual void func1() = 0; // 接口的声明
    virtual void func2(int a) = 0;
    virtual void func3(int a, int b) = 0; 
};

class Son :public Father {
public:
    // 接口的实现
    virtual void func1() {

    }
    virtual void func2(int a) {
        
    }
    virtual void func3(int a, int b){
        
    }
};

void test1(){
}

int main() {
    test1();
    return 0;
}
