#include <stdio.h>

// �������ĺ�
#define MY_ADD(a, b) a + b

int testDefine() {
	printf("result=%d\n", MY_ADD(10, 20)); // 10+20
	printf("result=%d\n", MY_ADD((10*10), (20*20))); // 10+20
}