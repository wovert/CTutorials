#include <iostream>
#include "data.h"
#include <stdlib.h>
#include <string.h>
using namespace std;


void test01() {
    Data ob = Data(01, 18); // ��ʾ���ù��캯��
    char *n = (char *)"÷��";
    ob.setName(n);
    cout << "ob.num=" << ob.getNum() << endl;
    cout << "ob.name=" << ob.getName() << endl;
    cout << "ob.age=" << ob.getAge() << endl;
    cout << "-------------" << endl;

    Data ob2 = Data(ob);
    char *name = (char *)"�����";
    ob.setName(name);
    cout << "ob2.num=" << ob2.getNum() << endl;
    cout << "ob2.name=" << ob2.getName() << endl;
    cout << "ob2.age=" << ob2.getAge() << endl;
    cout << "-------------" << endl;


}
void test02() {
    Data ob3 = Data(2, 20, 100, 200);
    char *n3 = (char *)"�����";
    ob3.setName(n3);
    cout << "ob3.num=" << ob3.getNum() << endl;
    cout << "ob3.name=" << ob3.getName() << endl;
    cout << "ob3.age=" << ob3.getAge() << endl;
    cout << "-------------" << endl;
}
void test03() {
        // malloc���ܵ��ù��캯�� free ���������������
    Data *d1 = (Data *)malloc(sizeof(Data));
    if (d1 == NULL) {
        cout << "����ʧ��" << endl;
    }
    if (d1 != NULL) {
        free(d1);
    }
    cout << "----�������Ϳռ�---------" << endl;
    int *p = new int(100);
    cout << "*p=" << *p << endl;
    delete p;

    cout << "----������������ռ�---------" << endl;
    int *pArr = new int[5]{1,2,3,4,5};
    for (int i=0; i<5; i++) {
        cout << pArr[i] << endl;
    }
    delete [] pArr;

    cout << "----������������ռ�2---------" << endl;
    // char *pChar = new char[5]{"hello"}; // ����
    // char *pChar = new char[5]{'h','e','l','l','o'};
    char *pChar = new char[5];
    strcpy(pChar, "hello");
    cout << pChar << endl;
    delete [] pChar;
}

void test04() {
    cout << "----�Զ�����������---------" << endl;
    Data *pData1 = new Data(2, 30);
    char *n4 = (char *)"C��";
    pData1->setName(n4);
    cout << "pData1->num=" << pData1->getNum() << endl;
    cout << "pData1->name=" << pData1->getName() << endl;
    cout << "pData1->age=" << pData1->getAge() << endl;
    delete pData1;
    cout << "-------------" << endl;
}

void test05() {


    cout << "----��������:�޲ι��캯��---------" << endl;
    // �Զ������޲ι��캯��5��
    Data dataArr[5];

    cout << "----��������:�вι��캯��---------" << endl;
    Data dataArr2[5] = {Data(01, 39), Data(02), Data(03, 19, 100, 200)};
}

void test06() {
    cout << "----��̬��������:�޲ι��캯��---------" << endl;
    Data *arr = NULL;
    arr = new Data[5]; // �Զ������޲ι��캯��
    delete [] arr;
}

void test07() {
    cout << "----��̬��������:�вι��캯��---------" << endl;
    Data *arr2 = new Data[5]{Data(1), Data(2, 18), Data(3, 30, 100, 300)};
    delete [] arr2;
    cout << "----end---------" << endl;
}

void test08() {
    cout << "Data::shareData=" << Data::shareData << endl;
}

int main(int argc, char *argvs[]) {
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    test08();

    return 0;
}