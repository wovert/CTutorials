#include <stdio.h>

void testConst() {
	const int num = 10;
	printf("num=%d\n", num);
	//num = 100; // error
	printf("&num=%p\n", &num);

	// ֪��num��ַ�����Լ�ӵ��޸�num��ֵ
	// ǿ��ת��Ϊint *����
	*(int *)(&num) = 100;
	printf("num=%d\n", num);

}