#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

static void demoMalloc() {
	int *addr = NULL;
	addr = (int *)malloc(sizeof(int));
	
	// 申请失败
	if (addr == NULL) {
		printf("malloc err\n");
		return;
	}

	printf("*addr=%d\n", *addr); // -842150451 不确定的值
	
	// 对堆区空间清0: addr:起始地址, 0:每个字节内容为0, sizeof(int): 填充的多少个字节
	memset(addr, 0, sizeof(int));

	printf("*addr=%d\n", *addr);

	// 对 addr的空间写入操作
	*addr = 1000;

	printf("*addr=%d\n", *addr);

	// 释放空间：空间使用权限的回收，是否对空间内容清0，这是不确定的
	free(addr);

}

static void demoCalloc() {
	int *arr = NULL;
	int n = 0;

	printf("请输入数组数量:");

	scanf("%d", &n);

	// 从堆区申请空间
	arr = (int *)calloc(n, sizeof(int));
	if (arr == NULL) {
		printf("calloc err\n");
		return;
	}

	int i;
	for (i = 0; i < n; i++) {
		printf("arr[%d]=%d ", i, arr[i]);
	}
	printf("\n");

	free(arr);
}

static void demoRealloc() {
	int *arr = NULL;
	int n = 0;
	int appendNum = 0;
	int i;

	printf("请输入数组数量:");

	scanf("%d", &n);

	// 从堆区申请空间
	arr = (int *)calloc(n, sizeof(int));
	if (arr == NULL) {
		printf("calloc err\n");
		return;
	}
	printf("old arr地址=%u\n", arr);
	 
	for (i = 0; i < n; i++) {
		scanf("%d", arr+i);
	}
	
	printf("arr数组内容为：");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("追加输入数组数量:");
	scanf("%d", &appendNum);
	
	arr = (int *)realloc(arr, (n+appendNum) * sizeof(int));

	for (i = n; i < n+appendNum; i++) {
		scanf("%d", arr + i);
	}
	
	// memset(arr, 0, (n + appendNum) * sizeof(int));
	
	printf("新arr数组内容为：");
	for (i = 0; i < (n + appendNum); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("new arr地址=%u\n", arr);


	// 防止多次释放
	if (arr != NULL) {
		free(arr);
		arr = NULL;
	}
}
void testMalloc() {
	//test1();
	//demoMalloc();
	//demoCalloc();
	demoRealloc();
}