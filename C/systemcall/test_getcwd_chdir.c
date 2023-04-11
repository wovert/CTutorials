#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 128


// 复制文件描述符
int main(void) {

	int ret = -1;
	char buf[SIZE];

	// 获取当前进程的工作目录
	memset(buf, 0, SIZE);
	if (NULL == getcwd(buf, SIZE)) {
	  perror("getcwd");
	  return 1;
	}
	printf("buf=%s\n", buf);

	// 改变当前进程的工作目录
	ret = chdir("/home");
	if (-1 == ret) {
	  perror("chdir");
	  return 1;
	}


	// 获取当前进程的工作目录
	memset(buf, 0, SIZE);
	if (NULL == getcwd(buf, SIZE)) {
	  perror("getcwd");
	  return 1;
	}
	printf("buf=%s\n", buf);

	return 0;
}
