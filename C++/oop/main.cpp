#include <iostream>
#include "data.h"
#include <stdlib.h>
#include <string.h>
using namespace std;


void test01() {
    Data ob = Data(01, 18); // 显示调用构造函数
    char *n = (char *)"梅西";
    ob.setName(n);
    cout << "ob.num=" << ob.getNum() << endl;
    cout << "ob.name=" << ob.getName() << endl;
    cout << "ob.age=" << ob.getAge() << endl;
    cout << "-------------" << endl;

    Data ob2 = Data(ob);
    char *name = (char *)"齐达内";
    ob.setName(name);
    cout << "ob2.num=" << ob2.getNum() << endl;
    cout << "ob2.name=" << ob2.getName() << endl;
    cout << "ob2.age=" << ob2.getAge() << endl;
    cout << "-------------" << endl;


}
void test02() {
    Data ob3 = Data(2, 20, 100, 200);
    char *n3 = (char *)"内马尔";
    ob3.setName(n3);
    cout << "ob3.num=" << ob3.getNum() << endl;
    cout << "ob3.name=" << ob3.getName() << endl;
    cout << "ob3.age=" << ob3.getAge() << endl;
    cout << "-------------" << endl;
}
void test03() {
        // malloc不能调用构造函数 free 不会调用析构函数
    Data *d1 = (Data *)malloc(sizeof(Data));
    if (d1 == NULL) {
        cout << "申请失败" << endl;
    }
    if (d1 != NULL) {
        free(d1);
    }
    cout << "----基本类型空间---------" << endl;
    int *p = new int(100);
    cout << "*p=" << *p << endl;
    delete p;

    cout << "----基本类型数组空间---------" << endl;
    int *pArr = new int[5]{1,2,3,4,5};
    for (int i=0; i<5; i++) {
        cout << pArr[i] << endl;
    }
    delete [] pArr;

    cout << "----基本类型数组空间2---------" << endl;
    // char *pChar = new char[5]{"hello"}; // 报错
    // char *pChar = new char[5]{'h','e','l','l','o'};
    char *pChar = new char[5];
    strcpy(pChar, "hello");
    cout << pChar << endl;
    delete [] pChar;
}

void test04() {
    cout << "----自定义数据类型---------" << endl;
    Data *pData1 = new Data(2, 30);
    char *n4 = (char *)"C罗";
    pData1->setName(n4);
    cout << "pData1->num=" << pData1->getNum() << endl;
    cout << "pData1->name=" << pData1->getName() << endl;
    cout << "pData1->age=" << pData1->getAge() << endl;
    delete pData1;
    cout << "-------------" << endl;
}

void test05() {


    cout << "----对象数组:无参构造函数---------" << endl;
    // 自动调用无参构造函数5次
    Data dataArr[5];

    cout << "----对象数组:有参构造函数---------" << endl;
    Data dataArr2[5] = {Data(01, 39), Data(02), Data(03, 19, 100, 200)};
}

void test06() {
    cout << "----动态对象数组:无参构造函数---------" << endl;
    Data *arr = NULL;
    arr = new Data[5]; // 自动调用无参构造函数
    delete [] arr;
}

void test07() {
    cout << "----动态对象数组:有参构造函数---------" << endl;
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