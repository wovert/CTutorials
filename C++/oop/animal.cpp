#include <string.h>
#include <iostream>
#include "animal.h"
#include "person.h"
using namespace std;

Animal1::Animal1() {
    public_a = 100;
};
Animal1::~Animal1() {
    cout << "Animal1 析构函数" << endl;
};
void Animal1::print() {
    cout << "----------Animal1::print()---------------" << endl;
    // cout << private_a << endl; // 不能访问
    cout << protected_a << endl; // 本类成员属性
    cout << "父类public_a=" << Person::public_a << endl;
    cout << "成员属性public_a=" << public_a << endl;
    cout << "-----------------------------------------" << endl;
}

Animal2::Animal2() {};
Animal2::~Animal2() {
    cout << "Animal2 析构函数" << endl;
};
void Animal2::print() {
    // cout << private_a << endl; // 不能访问
    cout << protected_a << endl; // 继承类内可以访问
    cout << public_a << endl;
}

Animal3::Animal3() {};
Animal3::~Animal3() {
    cout << "Animal3 析构函数" << endl;
};
void Animal3::print() {
    // cout << private_a << endl; // 不能访问
    cout << protected_a << endl; // 继承类内可以访问
    cout << public_a << endl;
}

void test1() {
    Animal1 a1;
    a1.print();
    cout << "成员属性public_a=" << a1.public_a << endl;
    cout << "父类public_a=" << a1.Person::public_a << endl;
    // cout << a1.protected_a << endl; // 不能访问

    a1.Person::print();
}

void test2() {
    Animal2 a2;
    a2.print();
    // cout << a2.public_a << endl; // 不能访问
    // cout << a2.protected_a << endl; // 不能访问
}

void test3() {
    Animal3 a3;
    a3.print();
    // cout << a3.public_a << endl; // 不能访问
    // cout << a3.protected_a << endl; // 不能访问
}

int main() {
    test1();
    // test2();
    // test3();
    return 0;
}