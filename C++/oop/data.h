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
            cout << "A Constructor()>>>>>>>>" << endl;
        }
        A(int a) {
             cout << "A Constructor(int)>>>>>>>>" << endl;
            this->property_a = a;
        }
        ~A() {
            cout << "A Destructor()>>>>>>>>" << endl;
        }
};
class B {
    private:
        int property_b;
    public:
        B() {
            cout << "B Constructor()>>>>>>>>" << endl;
        }
        B(int b) {
             cout << "B Constructor(int)>>>>>>>>" << endl;
            this->property_b = b;
        }
        ~B() {
            cout << "B Destructor()>>>>>>>>" << endl;
        }
};

class Data {
    private:
        int num;
        int age;
        char *name;
        A oba;
        B obb;
        static int shareData; 
    // public:
        const static int onlyData; 
        mutable int mnum;
    public:
        static int getShareData() {
            return Data::shareData;
        }
        static int getOnlyData() {
            return Data::onlyData;
        }
        Data() {
            cout << "Data Constructor()>>>>>>>>" << endl;
        }
        Data(int num) {
            cout << "Data Constructor(int)>>>>>>>>" << endl;
            this->num = num;
        }
        Data(int n, int a): num(n), age(a)  {
            cout << "Data(int n, int a): num(n), age(a)>>>>>>>>" << endl;
        }
        Data(int n, int a, int a_value, int b_value): num(n), age(a), oba(a_value), obb(b_value)  {
            cout << "Data(int n, int a, int a_value, int b_value): num(n), age(a), oba(a_value), obb(b_value)>>>>>>>>" << endl;
        }
        Data(const Data &d) {
            cout << "Data(const Data &d)>>>>>>>>" << endl;
            name = (char *)malloc(strlen(d.name) + 1);
            if (name == NULL) {
                cout << "Not can Create memory space >>>>>>>>" << endl;
            }
            strcpy(name, d.name);
            this->num = d.num;
            this->age = d.age + 10;
        }
        ~Data() {
            cout << "~Data()>>>>>>>>" << endl;
            if (this->name != NULL) {
                cout << "free name space >>>>>>>>" << this->name << endl;
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