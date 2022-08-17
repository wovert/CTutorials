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
            cout << "�޲ι��캯��A>>>>>>>>" << endl;
        }
        A(int a) {
             cout << "�вι��캯��A>>>>>>>>" << endl;
            this->property_a = a;
        }
        ~A() {
            cout << "��������A>>>>>>>>" << endl;
        }
};
class B {
    private:
        int property_b;
    public:
        B() {
            cout << "�޲ι��캯��B>>>>>>>>" << endl;
        }
        B(int b) {
             cout << "�вι��캯��B>>>>>>>>" << endl;
            this->property_b = b;
        }
        ~B() {
            cout << "��������B>>>>>>>>" << endl;
        }
};

class Data {
    private:
        int num;
        int age;
        char *name;
        // �����Ա
        A oba;
        B obb;
        static int shareData; // ��̬��Ա����������������
    // public:
        const static int onlyData; // ��������
        mutable int mnum;
    public:
        static int getShareData() {
            return Data::shareData;
        }
        static int getOnlyData() {
            return Data::onlyData;
        }
        Data() {
            cout << "�޲ι��캯��Data>>>>>>>>" << endl;
        }
        Data(int num) {
            cout << "�вι��캯��Data>>>>>>>>" << endl;
            this->num = num;
        }
        // ��ʼ���б�: ��Ա��(������),��Ա��n(������n)
        Data(int n, int a): num(n), age(a)  {
            cout << "�вι��캯��Data>>>>>>>>" << endl;
        }
        // ��ʼ���б�: ��Ա��(������),��Ա��n(������n)
        Data(int n, int a, int a_value, int b_value): num(n), age(a), oba(a_value), obb(b_value)  {
            cout << "�вι��캯��Data>>>>>>>>" << endl;
        }
        Data(const Data &d) {
            cout << "�������캯��Data>>>>>>>>" << endl;
            name = (char *)malloc(strlen(d.name) + 1);
            if (name == NULL) {
                cout << "����name�ַ���ʧ��>>>>>>>>" << endl;
            }
            strcpy(name, d.name);
            this->num = d.num;
            this->age = d.age + 10;
        }
        ~Data() {
            cout << "��������Data>>>>>>>>" << endl;
            if (this->name != NULL) {
                cout << "�ͷŷ���name�ַ����ɹ�>>>>>>>>" << this->name << endl;
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