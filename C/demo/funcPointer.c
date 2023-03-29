#include <stdio.h>

int jia(int v1, int v2) {
	return v1 + v2;
}

int jian(int v1, int v2) {
	return v1 - v2;
}

int dynamicFunc(int v1, int v2, int (*funcP)(int, int)) {
	return funcP(v1, v2);
}

void testFuncPointer() {
	printf("10+5=%d\n", dynamicFunc(10, 5, jia));
	printf("10-5=%d\n", dynamicFunc(10, 5, jian));
}