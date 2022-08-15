#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Data {
    private:
        int num;
        char *name;
    public:
        Data(int num) {
            this->num = num;
        }
        Data(const Data &d) {
            cout << "�������캯��>>>>>>>>" << endl;
            name = (char *)malloc(strlen(d.name) + 1);
            if (name == NULL) {
                cout << "����name�ַ���ʧ��>>>>>>>>" << endl;
            }
            strcpy(name, d.name);
            this->num = d.num;
        }
        ~Data() {
            cout << "��������>>>>>>>>" << endl;
            if (this->name != NULL) {
                cout << "�ͷŷ���name�ַ����ɹ�>>>>>>>>" << this->name << endl;
                free(this->name);
                this->name = NULL;
            }
        }
        void setNum(int n);
        int getNum(void);
        void setName(char *str);
        char *getName(void);
};

#endif