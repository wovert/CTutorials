#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Maker {
public:
    string name;
    Maker() {
        name = "����";
        cout << "�޲ι���" << endl;
    }
    ~Maker() {
        cout << "��������" << endl;
    }
    /**
     * @brief �º������ã�
     * 1. �������ά��
     * 2. ������Ȩ�޵ĵ��ú���
     * 3. ��Ϊ�㷨�Ĳ���
     * 
     */
    void operator()() {
        cout << "�޲ηº���" << endl;
    }
    void operator()(int v1, int v2) {
        cout << "�вηº���" << endl;
    }
    void print() {
        cout << "Maker print method" << endl;
    }
};

class SmartPoint {
public:
    SmartPoint(Maker *m) {
        this->pMaker = m;
    }
    // ����ָ�������
    Maker* operator->() {
        return this->pMaker;
    }
    // �����ǻ�
    Maker& operator*() {
        return *pMaker;
    }
    ~SmartPoint() {
        if (this->pMaker != NULL) {
            cout << "SmartPoint ��������" << endl;
            delete this->pMaker;
            this->pMaker = NULL;
        }
    }
private:
    Maker *pMaker;
};


void test01() {
    // ����delete
    Maker *p = new Maker;

    SmartPoint sm(p); // ջ����������������
    sm->print();

    (*sm).print();
}

void test02() {
    Maker m;
    m();
    m(1, 2);
}

int main() {
    // test01();
    test02();
    system("pause");
    return 0;
}