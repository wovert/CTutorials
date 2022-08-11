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
            sprintf(s, "姓名：%s 学号:%d\n", name.c_str(), number);
            return s;
        }

};

void test() {
    Student stu;
    stu.setNumber(1);
    // char name[] = "张三";
    string name = "张三";
    stu.setName("张三");
    printf("%s\n", stu.getInfo());
}

int main() {
    test();
    return 0;
}