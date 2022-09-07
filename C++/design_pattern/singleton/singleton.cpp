#include <iostream>
#include "Singleton.h"

using namespace std;
Singleton::Singleton() {};
Singleton::Singleton(const Singleton &ob) {};

Singleton* Singleton::getInstance() {
    if (instance == NULL) {
        instance = new Singleton();
    }
    return instance;
};


void Singleton::deleteSingleton() {
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}

void Singleton::setData(int data) {
    this->data = data;
};
int Singleton::getData(void) {
    return data;
};

// 类外初始化，Singleton::作用域，编译器当作在类内
Singleton *Singleton::instance = new Singleton();


int main() {
    Singleton *p1 = Singleton::getInstance();
    p1->setData(200);
    cout << "p1->data = " << p1->getData() << endl;

    Singleton *p2 = Singleton::getInstance();
    cout << "p2->data = " << p2->getData() << endl;
    return 0;
}

