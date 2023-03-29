#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void array() {
	int arr[] = { 1,2,3,4,5 };
	int count = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < count; i++) {
		printf("%d\n", arr[i]); // 随机访问-858993460
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

void arrayPoint() {
	int arr[5] = { 10, 20, 30, 40, 50 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	int *p = &arr[0];
	printf("*p = %d\n", *p);
	p++; // p = p + 1 指针跳转到数组第二个元素地址
	printf("*p = %d\n", *p);
	
	p = &arr[0];
	for (i = 0; i<n; i++) {
		//printf("%d ", arr[i]);
		printf("%d ", *(p+i));
	}
	p++;
	p++;
	printf("\n%d\n", *(++p + 1));
	printf("\n");
}

void getArray2Point() {
	int arr[5] = { 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	int *p = &arr[0];
	printf("请输入%d个int 数据\n", n);

	for (i = 0; i < n;i++) {
		//scanf("%d", &arr[i]);
		//scanf("%d", p + i);
		scanf("%d", arr+i);
	}
	for (i = 0; i < n; i++) {
		printf("%d ", *(p + i));
	}
	printf("\n");
	printf("%d\n", arr[1]);
	printf("%d\n", *(arr+1));
	printf("%d\n", *(1 + arr));
	printf("%d\n", 1 + *arr);
	printf("%d\n", 1[arr]);
	printf("\n");
}

void testArr() {
	int arr[5] = { 10, 20, 30, 40, 50 };
	printf("%u\n", arr); // 首元素的地址 2336093544 
	printf("%u\n", arr + 1); // 2336093548
	printf("---------------\n"); 
	printf("%u\n", &arr); // 2336093544
	printf("%u\n", &arr+1); // 2336093564
}

void testPointSub() {
	int arr[5] = { 10, 20, 30, 40, 50 };
	int *p1 = arr;
	int *p2 = arr + 3;

	printf("%d\n", *p1++); // 10  *(p1++) = *p1, p1=p1+1 
	printf("%d\n", (*p1)++); // 20 (*p1)=20, *p1=20+1=21
	printf("%d\n", *(p1++)); // 21 *(p1)=21, p1=p1+1
	printf("%d\n", *p1);	//  30

	// 1. 指向统一数组的两个指针变量相减 返回的是相差元素的个数
	int result = p2 - p1;
	printf("*p1=%d\n", *p1); // 10
	printf("*p2=%d\n", *p2); // 40
	printf("result=%d\n", result); // 3

	// 2. 指向同一数组的两个指针变量 可以比较大小 
	if (p2 > p1) {
		printf(">\n");
	}
	else {
		printf("<=\n");
	}

	// 3. 指向同一数组的两个指针变量可以赋值
	p1 = p2; // p1 和 p2 指向同一处
	printf("*p1=%d\n", *p1); // 40
	printf("*p2=%d\n", *p2); // 40

	// 4. 指向同一数组的两个指针变量相加越界
	//p1 + p2; // error 

	// 5. [] 不越界的情况下可以为负数
	printf("p2[-2]=%d\n", p2[-2]); // 20
}


static void pointArray() {
	int num1 = 10;
	int num2 = 20;
	int num3 = 30;
	// 指针数组 arr[0] = &num1, arr[1]=&num2, arr[2]=&num3
	int *arr[3] = { &num1, &num2, &num3 };

	printf("%d\n", *arr[1]); // *&num2=num2=20
	printf("%d\n", sizeof(arr)); // 24

	char *arr2[3];
	printf("%d\n", sizeof(arr2)); // 24

	printf("-----------------\n");

	char *names[3] = {"张三", "齐达内", "Ronalduo"};
	printf("%d\n", sizeof(names)); // 24
	printf("%s\n", names[1]); //   齐达内
	printf("%c\n", *(names[2] + 2)); // o
}

static void arrayPointer() {
	int arr[5] = {10,20,30,40,50};
	
	
	// arr[5] => (*p)[5]
	int(*p)[5];  // 数组指针：本质是指针变量，保存的是数组的首地址&arr

	p = &arr;
	
	printf("%d\n", sizeof(p)); // 8字节

	printf("p=%u\n", p);
	printf("p+1=%u\n", p+1); // 内存地址占用4个字节
	printf("%d\n", *(*p+3)); // *p=*&arr=arr => *(arr+3) = *(*p+3)
	printf("%d\n", *(*(p+0)+3));
	printf("%d\n", *(p[0] + 3));
	printf("%d\n", p[0][3]);
}

static void array2Pointer() {
	int arr[3][4] = { {1,2,3,4},{5,6,7,9},{10,11,12,13} };
	int *p1 = &arr[0][0];
	int(*p)[4]; // 数值指针
	p = arr; // p和arr完全等价

	// 用户p和arr取出7的值
	printf("%d\n", arr[1][2]);
	printf("%d\n", *(*(arr + 1) + 2));
	printf("%d\n", p[1][2]);
	printf("%d\n", *(*(p+1)+2));
	printf("%d\n", *(p1+6));

}

void testArray() {
	//array();
	//arrayPoint();
	//getArray2Point();
	//testArr();
	//testPointSub();
	//pointArray();
	//arrayPointer();
	array2Pointer();
}