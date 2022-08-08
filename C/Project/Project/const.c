#include <stdio.h>

const int a = 1; // 常量区，一旦初始化，不能修改

void testConst() {
	int *p = (int *)&a;
	//*p = 1000;
	printf("%d\n", a);

	const int num = 10;
	printf("num=%d\n", num);
	//num = 100; // error
	printf("&num=%p\n", &num);

	// 知道num地址，可以间接的修改num的值
	// 强制转换为int *类型
	*(int *)(&num) = 100;
	printf("num=%d\n", num);

}