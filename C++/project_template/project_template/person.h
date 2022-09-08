#define _CRT_SECURE_NO_WARNINGS
#ifndef __PERSON_H__
#define __PERSON_H__
#include <string.h>

class Person {
private:
	int private_a;
protected:
	int protected_a;
public:
	int public_a;
public:
	Person();
	Person(int, int, int);
	~Person();
	void print();
};

#endif