#include <stdio.h>

// 字符指针数组
void charPointerArray() {
	//char *p1 = "haha";
	//char *p2 = "hehe";
	//char *p3 = "xixi";
	//char * num[3] = {p1, p2, p3};

	char* num[3] = { "haha", "hehe", "xixi" };
	for (int i = 0; i < 3; i++) {
		printf("%s\n", num[i]);
	}
	printf("%c\n", *(num[1] + 1)); // e
	printf("%c\n", num[1][1]); // e

	// 定义指针保存num数组首元素的地址 &num[0]  = num
	char** p = num;

	printf("%s\n", *p);
	printf("%s\n", *(p+1));
	printf("%s\n", *(p + 2));
	printf("%c\n", *(*(p+2)+1)); //i

	system("pause");
}