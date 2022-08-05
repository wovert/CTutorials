#include <iostream>

using namespace std;

inline int sum();

// ����
inline int sum(int a, int b) {
	return a + b;
}

// ��ͨ����������ջ�ռ�
int normalFunc(int a, int b) {
	return a + b;
}
// ����ջ�ռ�

int main(int argc, char *argv[])
{
	// ���ú��������ڴ�ռ�
	int result = normalFunc(10, 20);

	cout << "result=" << result << endl;

	// �������˴��滻�������룬�����ں������� �����Ϊ int c = 20 + 40;
	// 1.���ں��������������
	// 2.Ƶ�����ú�����ʹ��inline
	int c = sum(10, 20);

	cout << "c=" << c << endl;

	cout << "----------" << endl;
	int a = 1;
	int b = 2;
	(a = b) = 4;
	cout << "a=" << a << endl; // 4
	cout << "b=" << b << endl; // 2

	(a > b ? a : b) = 4;
	cout << "a=" << a << endl; // 4
	cout << "b=" << b << endl; // 2

	return 0;
}
