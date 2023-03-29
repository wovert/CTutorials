#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void testRand() {
	int i;
	printf("time(0) = %d\n", time(0));

	srand(time(0));

	for (i = 0; i < 20; i++) {
		// 0~49
		printf("%d ", rand() % 50);
		// 100~150
		printf("%d ", rand()%51 + 100);
	}
	printf("\n");
}