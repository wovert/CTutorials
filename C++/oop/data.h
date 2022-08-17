#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class A {
    private:
        int property_a;
    public:
        A() {
            cout << "无参构造函数A>>>>>>>>" << endl;
        }
        A(int a) {
             cout << "有参构造函数A>>>>>>>>" << endl;
            this->property_a = a;
        }
        ~A() {
            cout << "析构函数A>>>>>>>>" << endl;
        }
};
class B {
    private:
        int property_b;
    public:
        B() {
            cout << "无参构造函数B>>>>>>>>" << endl;
        }
        B(int b) {
             cout << "有参构造函数B>>>>>>>>" << endl;
            this->property_b = b;
        }
        ~B() {
            cout << "析构函数B>>>>>>>>" << endl;
        }
};

class Data {
    private:
        int num;
        int age;
        char *name;
        // 对象成员
        A oba;
        B obb;
        static int shareData; // 静态成员变量（类中声明）
    // public:
        const static int onlyData; // 类中声明
        mutable int mnum;
    public:
        static int getShareData() {
            return Data::shareData;
        }
        static int getOnlyData() {
            return Data::onlyData;
        }
        Data() {
            cout << "无参构造函数Data>>>>>>>>" << endl;
        }
        Data(int num) {
            cout << "有参构造函数Data>>>>>>>>" << endl;
            this->num = num;
        }
        // 初始化列表: 成员名(参数名),成员名n(参数名n)
        Data(int n, int a): num(n), age(a)  {
            cout << "有参构造函数Data>>>>>>>>" << endl;
        }
        // 初始化列表: 成员名(参数名),成员名n(参数名n)
        Data(int n, int a, int a_value, int b_value): num(n), age(a), oba(a_value), obb(b_value)  {
            cout << "有参构造函数Data>>>>>>>>" << endl;
        }
        Data(const Data &d) {
            cout << "拷贝构造函数Data>>>>>>>>" << endl;
            name = (char *)malloc(strlen(d.name) + 1);
            if (name == NULL) {
                cout << "分配name字符串失败>>>>>>>>" << endl;
            }
            strcpy(name, d.name);
            this->num = d.num;
            this->age = d.age + 10;
        }
        ~Data() {
            cout << "析构函数Data>>>>>>>>" << endl;
            if (this->name != NULL) {
                cout << "释放分配name字符串成功>>>>>>>>" << this->name << endl;
                free(this->name);
                this->name = NULL;
            }
        }
        void setNum(int n);
        int getNum(void);
        void setAge(int n);
        int getAge(void);
        void setName(char *str);
        char *getName(void);
        void getInfo() const;
        void envNum() const;
};

#endif