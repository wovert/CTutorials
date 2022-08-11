#include <stdio.h>
#include <stdarg.h>


// int a 变量总数
int printStr(int a, ...) {
	va_list v1; // 参数列表
	int temp = 0;
	va_start(v1, a);
	for (int i = 0; i < a; i++) {
		temp += (int)va_arg(v1, int);
	}
	va_end(v1);
	return temp;
}

int testPoint() {
	int d[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	// p 是二位数组的首地址
	// *p 是第一个元素的数组的首地址 *p=arrayName
	// **p 是第一个元素的数组的第一个元素的首地址 **p=arrayName[0][0] 
	int(*p)[3];
	p = d;

	int *a = d;

	printf("%d\n", (*p[2] + 2)); // 9
	printf("%d\n", **p+2); // 3
	printf("%d\n", **p + 5); // 6
	printf("%d\n", (*a+2)+2); // 5
	printf("%d\n", *a+4); // 5

	int result = printStr(3, 10, 20, 30);
	printf("result=%d\n", result);

	//int num = 0x01020304;
	//char *p;
	//p = &num;
	//printf("%#x\n", *(p + 3));
	return 0;
}

