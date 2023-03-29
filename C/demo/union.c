#include <stdio.h>

union DATA {
	char a;
	short b;
	int c;
};

void testUnion() {
	union DATA A;
	printf("%d\n", sizeof(union DATA));

	A.a = 10;
	A.b = 20;
	A.c = 256;

	printf("%d\n", A.a + A.b + A.c); // 512

	union DATA B;

	B.c = 0x01020304;
	B.b = 0x0102;
	B.a = 0x01;

	// B.c = 0x01020101
	// B.b = 0x00000101
	// B.c = 0x00000001
	printf("%#x\n", B.a + B.b + B.c); // 0x01020203
}