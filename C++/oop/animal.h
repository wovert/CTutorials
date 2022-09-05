#define _CRT_SECURE_NO_WARNINGS
#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string.h>
#include "person.h"

class Animal1 :public Person {
private:
    int num;
public:
    int public_a;
public:
    Animal1();
    ~Animal1();
    void print();
};

class Animal2 :protected Person {
private:
    int num;
public:
    Animal2();
    ~Animal2();
    void print();
};

class Animal3 :private Person {
private:
    int num;
public:
    Animal3();
    ~Animal3();
    void print();
};

#endif