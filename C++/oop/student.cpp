#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>

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
            // 从堆区空间申请
            // school = (char *)malloc(strlen(tmp) + 1);
            school = strdup(tmp);
            strcpy(school, tmp);
            cout << "构造函数" << endl;
        }
        ~Student() {
            // 释放堆区空间
            cout << "析构函数" << endl;
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
        char* getInfo() {
            char *s;
            sprintf(s, "姓名%s 年龄:%d 学校:%s\n", name.c_str(), number, school);
            return s;
        }

};

void test() {
    Student stu("职业高中", 1);
    // stu.setNumber(1);
    // char name[] = "张三";
    string name = "张三";
    stu.setName(name);
    printf("%s\n", stu.getInfo());
}

int main() {
    test();
    return 0;
}