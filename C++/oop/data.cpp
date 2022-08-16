#include "data.h"

void Data::setNum(int n) {
    num = n;
}
int Data::getNum(void) {
    return num;
}
void Data::setAge(int n) {
    age = n;
}
int Data::getAge(void) {
    return age;
}
void Data::setName(char *name) {
    this->name = name;
}
char * Data::getName(void) {
    return this->name;
}
int Data::shareData = 100; // 静态成员变量类外定义+初始化
