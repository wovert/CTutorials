#include <iostream>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

// �Զ����������ͣ������������Ż�
struct Maker {

	// ���캯��
	Maker() {
		a = 100;
	}
	int a;
};

const int gAge = 30;
int main() {

	int *gAgeP = (int *)&gAge;
	//*gAgeP = 2000; // �����������޸�
	cout << "gAgeP:" << *gAgeP << endl;
	
	// ��ֹ�Ż���ʹ��age���������򲻽��г����滻����
	volatile const int age = 10;
	int *ageP = (int *)&age;
	*ageP = 1000;
	cout << "age:" << age << endl;
	cout << "*ageP:" << *ageP << endl;


	extern const int a;
	cout << "extern a:" << a << endl;

	int aa = 10;
	const int b = a; // ����ñ�����const ���εľֲ�������ֵ�������������Ż�
	int *pp = (int *)&b;
	*pp = 100;
	cout << "b=" << b << endl;
	cout << "*pp=" << *pp << endl;

	const Maker ma;
	cout << ma.a << endl; // 100
	Maker *maP = (Maker *)&ma;  
	maP->a = 200;
	cout << ma.a << endl; // 200, û���Ż��������Ż��Զ�����������

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