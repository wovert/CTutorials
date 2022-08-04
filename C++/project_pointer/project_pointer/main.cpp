#include <iostream>
using namespace std;

void testConst() {
	int age = 10;
	int height = 30;

	// const ���ε��ұߵ�����

	// *p1�ǳ�����p1���ǳ���
	const int *p1 = &age;
	// *p1 = 20;
	p1 = &height;
	// *p1 = 40;


	// const int *p1 = &age ��ͬ
	int const *p2 = &age;

	// p3�ǳ�����*p3 ���ǳ���
	int * const p3 = &age;
	*p3 = 20; // age = 20
	// p3 = &height;
	*p3 = 40; // height = 40;



	// p4,p5�ǳ����� *p4,*p5�ǳ���
	const int * const p4 = &age;
	int const * const p5 = &age;

	// *p5 = 20;
	// p5 = &height;
	// *p5 = 40;

	struct Student { int age; };

	Student stu1 = { 10 };
	Student stu2 = { 20 };

	// *pStu1 �ǳ��� �����޸ĳ�Ա����, pStu1���ǳ���
	const Student *pStu1 = &stu1;

	// *pStu1�ǳ��������޸�
	// *pStu1 = stu2;

	// ָ��ָ���ڴ�ռ䲻���޸�
	// (*pStu1).age = 30;
	// pStu1->age = 30;

	// ָ��ָ��ĵ�ַ�����޸�
	pStu1 = &stu2;

	// pStu2�ǳ�����*pStu2���ǳ���
	Student * const pStu2 = &stu2;

	// *pStu2ָ��������޸�Ϊstu1
	*pStu2 = stu1;

	// *pStu2ָ�������stu1������age�޸�
	(*pStu2).age = 30;

	// �޸�ָ��ָ����ڴ�ռ�
	pStu2->age = 30;

	// ָ����������޸�
	//pStu2 = &stu1;


	// �ܽ�: ����*pStu1�����޸�ָ��ָ����ڴ�ռ�ͳ�Ա����ֵ
	// �ܽ�: ����pStu1�����޸�ָ����������µ��ڴ��ַ��
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

int main() {
	// testConst();
	testReference();
	
	int a = 10;
	int b = 20;
	// swap(&a, &b);
	swap(a, b);
	cout << "a=" << a << ",b=" << b << endl;

	getchar();
	return 0;
}