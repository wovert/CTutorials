#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        int number;
        // char *name;
        // char name[100];
        string name;
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
            sprintf(s, "������%s ѧ��:%d\n", name.c_str(), number);
            return s;
        }

};

void test() {
    Student stu;
    stu.setNumber(1);
    // char name[] = "����";
    string name = "����";
    stu.setName("����");
    printf("%s\n", stu.getInfo());
}

int main() {
    test();
    return 0;
}