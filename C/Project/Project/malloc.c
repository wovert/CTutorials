#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

static void demoMalloc() {
	int *addr = NULL;
	addr = (int *)malloc(sizeof(int));
	
	// ����ʧ��
	if (addr == NULL) {
		printf("malloc err\n");
		return;
	}

	printf("*addr=%d\n", *addr); // -842150451 ��ȷ����ֵ
	
	// �Զ����ռ���0: addr:��ʼ��ַ, 0:ÿ���ֽ�����Ϊ0, sizeof(int): ���Ķ��ٸ��ֽ�
	memset(addr, 0, sizeof(int));

	printf("*addr=%d\n", *addr);

	// �� addr�Ŀռ�д�����
	*addr = 1000;

	printf("*addr=%d\n", *addr);

	// �ͷſռ䣺�ռ�ʹ��Ȩ�޵Ļ��գ��Ƿ�Կռ�������0�����ǲ�ȷ����
	free(addr);

}

static void demoCalloc() {
	int *arr = NULL;
	int n = 0;

	printf("��������������:");

	scanf("%d", &n);

	// �Ӷ�������ռ�
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

	printf("��������������:");

	scanf("%d", &n);

	// �Ӷ�������ռ�
	arr = (int *)calloc(n, sizeof(int));
	if (arr == NULL) {
		printf("calloc err\n");
		return;
	}
	printf("old arr��ַ=%u\n", arr);
	 
	for (i = 0; i < n; i++) {
		scanf("%d", arr+i);
	}
	
	printf("arr��������Ϊ��");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("׷��������������:");
	scanf("%d", &appendNum);
	
	arr = (int *)realloc(arr, (n+appendNum) * sizeof(int));

	for (i = n; i < n+appendNum; i++) {
		scanf("%d", arr + i);
	}
	
	// memset(arr, 0, (n + appendNum) * sizeof(int));
	
	printf("��arr��������Ϊ��");
	for (i = 0; i < (n + appendNum); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("new arr��ַ=%u\n", arr);


	// ��ֹ����ͷ�
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