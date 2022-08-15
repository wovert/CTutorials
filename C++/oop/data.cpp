#include "data.h"

void Data::setNum(int n) {
    num = n;
}
int Data::getNum(void) {
    return num;
}
void Data::setName(char *name) {
    this->name = name;
}
char * Data::getName(void) {
    return this->name;
}
