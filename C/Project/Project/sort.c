#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

static void bubble() {
	int i;
	int n = 0;
	int *arr = NULL;
	printf("���������ݵĸ�����");
	scanf("%d", &n);

	// ����Ԫ�صĸ�������ռ�
	arr = (int *)calloc(n, sizeof(int));
	if (NULL == arr) {
		perror("calloc");
		return;
	}

	// ���̶�̬���� ��ȡ����
	printf("������%d��int����\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	// ����
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

	// ����
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	// �ͷſռ�
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