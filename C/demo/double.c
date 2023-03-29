#include <stdio.h>

void doubleTest() {
	double tmp = 0.3; // 0.3 0.299999 0.7 0.699999
	// ĞŞÕıÖµ
	printf("%d\n", (int)((tmp+0.000001)*10));

	double bai = 100.0;
	if (bai > bai - 0.000001 && bai < bai + 0.000001) {
		printf("bai == 100\n");
	} else {
		printf("bai != 100\n");
	}
}