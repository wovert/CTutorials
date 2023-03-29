#include <stdio.h>
#include <stdlib.h>

void testTime() {
	// 当前系统时间, time_t 相当于long类型，单位为毫秒
	time_t tm = time(NULL);//得到系统时间
	srand((unsigned int)tm);//随机种子只需要设置一次即可

	int r = rand();
	printf("r = %d\n", r);
}