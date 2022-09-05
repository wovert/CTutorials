#include <iostream>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

int func() {
    return 8;
}

// sum_v1
int sum(int &v1, int &v2) {
    cout << "sum(int &v1, int &v2)" << endl;
    return v1 + v2;
}

// sum_v2
int sum(const int &v1, const int &v2) {
    cout << "sum(const int &v1, const int &v2)" << endl;
    return v1 + v2;
}

// del_v1
int del(int *v1, int *v2) {
    cout << "del(int *v1, int *v2)" << endl;
    return *v1 - *v2;
}

// del_v2
int del(const int *v1, const int *v2) {
    cout << "del(const int *v1, const int *v2)" << endl;
    return *v1 - *v2;
}


void test03() {

    // not const parameters
    int a = 10;
    int b = 20;
    sum(a, b); // call sum_v1
    del(&a, &b); // call del_v1

    // const parameters
    sum(10, 20); // sum_v2
    // del(10, 20); // del_v2
    const int c = 10;
    const int d = 20;
    sum(c, d); // sum_v2
    del(&c, &d); // sum_v2
}

void test02() {
    int age = 10;
    const int &ref = 30; 

    const double &refDouble = age;

    age = 18;

    // point to diferrence datatype will create temp variable
    cout << "refDouble=" << refDouble << endl; // 10
    cout << "age=" << age << endl; // 18

    // ref = 20; // error: assignment of read-only reference 'ref'

    int a = 1;
    int b = 2;
    // int &ref2 = a + b; // error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
    const int &ref2 = a + b; // ok
    cout << "ref2=" << ref2 << endl; // 3

    const int &ref3 = func();
    cout << "ref3=" << ref3 << endl; // 8
}

void test01() {
    int age = 18;
    int num = 66;

    // pAge=NoCan, *pAge=Can
    int * const pAge = &age;
    *pAge = 20;
    // pAge = &num; // error: assignment of read-only variable 'pAge'

    cout << "age=" << age << endl; // 20

    
    const int &ref = age;  // readonly ref
    int const &ref2 = age;  // readonly ref
    
    // ref = 30; // error: assignment of read-only reference 'ref'

    // ref2 = 30; // error: assignment of read-only reference 'ref2'

    // 这里const 有没有都一样
    // int & const ref3 = age; // 'const' qualifiers cannot be applied to 'int&' 


    const int *p = &age; // readonly *p
    // *p = 30; // error: assignment of read-only location '* p'

    age = 100;
    cout << "ref=" << ref << endl; // 100
    cout << "*p=" << *p << endl; // 100
}

int main() {
    // test01();
    test02();
    // test03();
    return 0;
}