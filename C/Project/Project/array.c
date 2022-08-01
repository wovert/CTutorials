#include <stdio.h>

void array(int argc, char *argv[]) {
	int arr[] = {1,2,3,4,5};
	int count = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < count; i++) {
		printf("%d\n", arr[i]); // Ëæ»ú·ÃÎÊ-858993460
	};
	printf("arr sizeof=%d\n", sizeof(arr));

	double salaries[5] = { 1000.0, 3299.92, 5000.29 };
	int count2 = sizeof(salaries) / sizeof(salaries[0]);
	for (int i = 0; i < count2; i++) {
		printf("%.2lf\n", salaries[i]);
	};
	printf("arr sizeof=%d\n", sizeof(salaries));

	int arr3[5] = { [1] = 20,[4] = 93 };
	int count3 = sizeof(arr3) / sizeof(arr3[0]);
	for (int i = 0; i < count3; i++) {
		printf("%d\n", arr3[i]);
	};
	printf("arr sizeof=%d\n", sizeof(arr3));

}