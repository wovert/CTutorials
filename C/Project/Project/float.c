#include <stdio.h>

void testFloat() {
	// ��Чλ����01234123412341234 = 13
	float var = 0.1234123412341234F;
	double d = 0.1234123412341234;
	printf("%.20f\n", var);
	printf("%.20fl\n", d);
}