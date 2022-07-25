#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "add.h"

// 宏：编译时替换
#define RKVIR 1

int main() {
    // 只读变量
	const int a = 1;
	printf("%d", RKVIR);
	int result = add(10, 30);
	printf("result=%d\n", result);

	_Bool flag = true;
	if (flag) {
		printf("Flag is true\n");
	}

	system("pause");
	return 0;
}