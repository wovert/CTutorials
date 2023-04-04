#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// 设置和获取文件状态标记
int main(void) {

	int fd = -1;
	int ret = -1;

	// 1. 打开文件
	fd = open("txt", O_WRONLY | O_CREAT, 0644);
	if (-1 == fd) {
		perror("open");
		return 1;
	}

	printf("fd=%d\n", fd);

	// 2. 获取文件状态标记
	ret = fcntl(fd, F_GETFL);
	if (-1 == ret) {
	  perror("fcntl");
	  return 1;
	}
        if (ret & O_APPEND) {
          printf("before append\n"); 	
	} else {
	  printf("before not append\n");
	}

	// 3. 设置文件状态标
	ret = ret | O_APPEND;
	ret = fcntl(fd, F_SETFL, ret);

	// 4. 获取文件状态标记
	
	ret = fcntl(fd, F_GETFL);
	if (-1 == ret) {
	  perror("fcntl");
	  return 1;
	}
        if (ret & O_APPEND) {
          printf("after append\n"); 	
	} else {
	  printf("after not append\n");
	}
	
	// 5. 关闭文件
	close(fd);


	return 0;
}
