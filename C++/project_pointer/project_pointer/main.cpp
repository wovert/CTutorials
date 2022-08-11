#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void testConst() {
	int age = 10;
	int height = 30;

	// const 修饰的右边的内容

	// *p1是常量，p1不是常量
	const int *p1 = &age;
	// *p1 = 20;
	p1 = &height;
	// *p1 = 40;


	// const int *p1 = &age 相同
	int const *p2 = &age;

	// p3是常量，*p3 不是常量
	int * const p3 = &age;
	*p3 = 20; // age = 20
	// p3 = &height;
	*p3 = 40; // height = 40;



	// p4,p5是常量， *p4,*p5是常量
	const int * const p4 = &age;
	int const * const p5 = &age;

	// *p5 = 20;
	// p5 = &height;
	// *p5 = 40;

	struct Student { int age; };

	Student stu1 = { 10 };
	Student stu2 = { 20 };

	// *pStu1 是常量 不能修改成员属性, pStu1不是常量
	const Student *pStu1 = &stu1;

	// *pStu1是常量不能修改
	// *pStu1 = stu2;

	// 指针指向内存空间不能修改
	// (*pStu1).age = 30;
	// pStu1->age = 30;

	// 指针指向的地址可以修改
	pStu1 = &stu2;

	// pStu2是常量，*pStu2不是常量
	Student * const pStu2 = &stu2;

	// *pStu2指向的内容修改为stu1
	*pStu2 = stu1;

	// *pStu2指向的内容stu1的属性age修改
	(*pStu2).age = 30;

	// 修改指针指向的内存空间
	pStu2->age = 30;

	// 指针变量不能修改
	//pStu2 = &stu1;


	// 总结: 常量*pStu1不能修改指针指向的内存空间和成员属性值
	// 总结: 常量pStu1不能修改指针变量（即新的内存地址）
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

// 接受指针类型的地址
void func(char **tmp) {
	char *p;
	p = (char *)malloc(64);
	memset(p, 0, 64);
	//strcpy(p, "夏红");
	char cont[] = "夏红";
	strcpy_s(p, strlen(cont)+1, cont);
	*tmp = p;
}


// 接受指针类型的地址
void funcRef(char * &tmp) {
	char *p;
	p = (char *)malloc(64);
	memset(p, 0, 64);
	//strcpy(p, "夏红");
	char cont[] = "夏红";
	strcpy_s(p, strlen(cont) + 1, cont);
	tmp = p;
}


// 指针的引用
void test02() {
	char *mp = NULL;
	// 传递指针类型的地址
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

	// 指针的引用
	test02();

	getchar();
	return 0;
}