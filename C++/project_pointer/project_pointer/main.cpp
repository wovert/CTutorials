#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void testConst() {
	int age = 10;
	int height = 30;


	const int *p1 = &age;
	// *p1 = 20;
	p1 = &height;
	// *p1 = 40;


	int const *p2 = &age;

	int * const p3 = &age;
	*p3 = 20; // age = 20
	// p3 = &height;
	*p3 = 40; // height = 40;



	const int * const p4 = &age;
	int const * const p5 = &age;

	// *p5 = 20;
	// p5 = &height;
	// *p5 = 40;

	struct Student { int age; };

	Student stu1 = { 10 };
	Student stu2 = { 20 };

	const Student *pStu1 = &stu1;

	// *pStu1????????????
	// *pStu1 = stu2;

	// (*pStu1).age = 30;
	// pStu1->age = 30;

	pStu1 = &stu2;

	Student * const pStu2 = &stu2;

	*pStu2 = stu1;

	(*pStu2).age = 30;

	pStu2->age = 30;

	//pStu2 = &stu1;


	// const Student *pStu1 = &stu1;
	// Student * const pStu2 = &stu2;
}

void testReference() {
	int age = 10;
	int &refAge = age;
	refAge = 20;

	cout << age << endl;
}
void swap(int *v1, int *v2) {
	int tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

void swapRef(int &v1, int &v2) {
	int tmp = v1;
	v1 = v2;
	v2 = tmp;
}

void func(char **tmp) {
	char *p;
	p = (char *)malloc(64);
	memset(p, 0, 64);
	//strcpy(p, "???");
	char cont[] = "???";
	strcpy_s(p, strlen(cont)+1, cont);
	*tmp = p;
}


void funcRef(char * &tmp) {
	char *p;
	p = (char *)malloc(64);
	memset(p, 0, 64);
	//strcpy(p, "???");
	char cont[] = "???";
	strcpy_s(p, strlen(cont) + 1, cont);
	tmp = p;
}


void test02() {
	char *mp = NULL;
	//func(&mp);
	funcRef(mp);
	cout << mp << endl;
}

int main() {
	// testConst();
	testReference();
	
	int a = 10;
	int b = 20;
	// swap(&a, &b);
	swap(a, b);
	cout << "a=" << a << ",b=" << b << endl;

	test02();

	getchar();
	return 0;
}