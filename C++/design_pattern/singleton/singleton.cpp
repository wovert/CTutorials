#include <iostream>
#include "Singleton.h"

using namespace std;

Singleton *Singleton::instance = new Singleton();


int main() {
    Singleton *p1 = Singleton::getInstance();
    p1->setData(200);
    cout << "p1->data = " << p1->getData() << endl;
    return 0;
}

