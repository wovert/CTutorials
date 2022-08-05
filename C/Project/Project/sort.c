#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

static void bubble() {
	int i;
	int n = 0;
	int *arr = NULL;
	printf("请输入数据的个数：");
	scanf("%d", &n);

	// 根据元素的个数申请空间
	arr = (int *)calloc(n, sizeof(int));
	if (NULL == arr) {
		perror("calloc");
		return;
	}

	// 键盘动态数组 获取输入
	printf("请输入%d个int数据\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	// 排序
	int j;
	for (i = 0; i < n - 1; i++) {
		int flag = 0;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = 0;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}

	printf("i=%d\n", i);

	// 遍历
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 释放空间
	if (arr != NULL) {
		free(arr);
		arr = NULL;
	}
}


static void testSortStruct() {

}

void testSort() {
	//bubble();
	testSortStruct();
}