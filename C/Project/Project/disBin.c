#include <stdio.h>

void disBin(char ch) {
	printf("%d = ", ch);
	int i = 8;
	while (i--) {
		if ((1<<i) & ch) {
			printf("1");
		} else {
			printf("0");
		}

		if (i % 4 == 0) {
			printf(" ");
		}
	}
	putchar(10);
}