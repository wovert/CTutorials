#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "person.h"

using namespace std;

class Student {
    private:
        int number;
        // char *name;
        // char name[100];
        string name;
        char *school;
    public:
        Student(const char *tmp, int number) {
            this->number = number;
            // �Ӷ����ռ�����
            // school = (char *)malloc(strlen(tmp) + 1);
            school = strdup(tmp);
            strcpy(school, tmp);
            cout << "���캯��" << endl;
        }
        ~Student() {
            // �ͷŶ����ռ�
            cout << "��������" << endl;
            if (school != NULL) {
                free(school);
                school = NULL;
            }
        }
    public:
        void setNumber(int no) {
            number = no;
        }
        // void setName(char* str) {
        void setName(string str) {
            name = str;
        }

        // ����������Ա����
        char* getInfo();

};

// ���ⶨ���Ա����
char* Student::getInfo() {
    char *s;
    sprintf(s, "����%s ����:%d ѧУ:%s\n", name.c_str(), number, school);
    return s;
}

void test() {
    Student stu("ְҵ����", 1);
    // stu.setNumber(1);
    // char name[] = "����";
    string name = "����";
    stu.setName(name);
    printf("%s\n", stu.getInfo());
}

int main() {
    test();
    return 0;
}