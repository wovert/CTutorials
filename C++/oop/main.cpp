#include <iostream>
#include "data.h"
using namespace std;

int main(int argc, char *argvs[]) {
    Data ob = Data(20); // ��ʾ���ù��캯��
    char *n = (char *)"÷��";
    ob.setName(n);
    cout << "ob.num=" << ob.getNum() << endl;
    cout << "ob.name=" << ob.getName() << endl;

    Data ob2 = Data(ob);
    char *name = (char *)"�����";
    ob.setName(name);
    cout << "ob2.num=" << ob2.getNum() << endl;
    cout << "ob2.name=" << ob2.getName() << endl;
    return 0;
}