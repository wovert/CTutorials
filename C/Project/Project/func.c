#include <stdio.h>

int sum(int v1, int v2) {
	return v1 + v2;
}

void testFunc() {
	int a = 10;
	int b = 20;
	
	int c = sum(a, b);
	//int c = (int(*)(int, int))(0x002F10D7)(a, b);

	printf("sum=%p\n", sum);
	printf("c=%d\n", c);
	
	char str[30] = ""; // 0 0 0 0 0 ...
	printf("%s\n", 0); // %s 将字符'\0' == 0 看成了0地址(null==(void *)0地址)

}