#include <stdio.h>

int sum(int v1, int v2) {
	return v1 + v2;
}

void testFunc() {
	int a = 10;
	int b = 20;
	
	int (*p) (int, int);
	p = sum;

	//int c = sum(a, b);
	int c = p(a, b);

	// 0x45e01163u
	printf("sum=%#x\n", sum);
	printf("p=%#x\n", p);
	printf("c=%d\n", c);

	// printf("%d\n", ( (int(*)(int,int))(0x809e1163) )(100, 200)    );

	
	
	char str[30] = ""; // 0 0 0 0 0 ...
	printf("%s\n", 0); // %s 将字符'\0' == 0 看成了0地址(null==(void *)0地址)

}