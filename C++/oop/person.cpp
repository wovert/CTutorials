#include <string.h>
#include <iostream>
#include "person.h"
using namespace std;

Person::Person() {
    this->private_a = 1;
    this->protected_a = 2;
    this->public_a = 3;
};

Person::Person(int a1, int a2, int a3) {
    this->private_a = a1;
    this->protected_a = a2;
    this->public_a = a3;
};

Person::~Person() {
    cout << "person 析构函数" << endl;
};

void Person::print() {
    cout << "----------Person::print()---------------" << endl;
    cout << "private_a=" << private_a << endl;
    cout << "protected_a=" << protected_a << endl;
    cout << "public_a=" << public_a << endl;
    cout << "--------------------------" << endl;
}