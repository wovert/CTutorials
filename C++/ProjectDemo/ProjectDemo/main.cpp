#define __cplushplus

#include <iostream>
using namespace std;

#include "math.h"
#include "math.h"
#include "math.h"
#include "math.h"

// ����ͬʱ��������ʵ�֣�����������extern "C" ����
// ����ʵ�ֿ��Բ�����
void func(); // name mangling
extern "C" void func(int);
extern "C" void other();

int main() {
	other();
	func();
	func(20);
	
	// ���ÿ�Դ��C��
	cout << sum(10, 20) << endl;
	cout << delta(30, 3) << endl;

	getchar();
	return 0;
}

void func() {

}

void func(int v) {

}
