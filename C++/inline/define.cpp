#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#define ADD(x, y) x + y;

void test() {
    int ref = ADD(10, 20) + 2;
    cout << "ref = " << ref << endl;
}

int main() {
    test();
    system("pause");
    return 0;
}