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
            cout << "¿½±´¹¹Ôìº¯Êý>>>>>>>>" << endl;
            name = (char *)malloc(strlen(d.name) + 1);
            if (name == NULL) {
                cout << "·ÖÅäname×Ö·û´®Ê§°Ü>>>>>>>>" << endl;
            }
            strcpy(name, d.name);
            this->num = d.num;
        }
        ~Data() {
            cout << "Îö¹¹º¯Êý>>>>>>>>" << endl;
            if (this->name != NULL) {
                cout << "ÊÍ·Å·ÖÅäname×Ö·û´®³É¹¦>>>>>>>>" << this->name << endl;
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