#include <stdio.h>
#include <stdlib.h>

void testTime() {
	// ��ǰϵͳʱ��, time_t �൱��long���ͣ���λΪ����
	time_t tm = time(NULL);//�õ�ϵͳʱ��
	srand((unsigned int)tm);//�������ֻ��Ҫ����һ�μ���

	int r = rand();
	printf("r = %d\n", r);
}