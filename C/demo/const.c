#include <stdio.h>

const int a = 1; // ��������һ����ʼ���������޸�

void testConst() {
	int *p = (int *)&a;
	//*p = 1000;
	printf("%d\n", a);

	const int num = 10;
	printf("num=%d\n", num);
	//num = 100; // error
	printf("&num=%p\n", &num);

	// ֪��num��ַ�����Լ�ӵ��޸�num��ֵ
	// ǿ��ת��Ϊint *����
	*(int *)(&num) = 100;
	printf("num=%d\n", num);

}