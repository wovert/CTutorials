#include <iostream>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

int main() {
	const int age = 30;

	// C
	// struct Date d = { 2022, 3, 8 };

	// C++ const ����֮���Ա�����޸�
	const Date d = { 2022, 3, 8 };
	
	// d.year = 2015;

	Date d1 = { 2011, 2, 5 };
	Date d2 = { 2013, 4, 8 };

	Date *p = &d1;
	p->year = 2015;

	// �����޸ĳ�Ա����
	(*p).month = 5;
	*p = d2;

	cout << d1.year << endl;

	const Date *p2 = &d1;
	// p2->year = 2015;
	// (*p2).month = 5;
	// *p2 = d2;


	// cout �Ǳ�ש����������󣬴�ӡ�ַ���
	// endl ��ˢ�»�������������
	cout << d1.year << endl;

	getchar();
	return 0;
}