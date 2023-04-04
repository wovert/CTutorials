#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

#define SIZE 128


// 复制文件描述符
int main(void) {

	DIR *dir = NULL;
	struct dirent *d = NULL;

	// 1.打开目录
	dir = opendir("test");

	if (NULL == dir) {
	  perror("opendir");
	  return 1;
	}
	printf("打开目录成功.\n");

	// 循环读取目录内容
	while(1) {
	  // 读取目录的内容
	  d = readdir(dir);
	  if (d == NULL) {
	    break;
	  }
	  printf("d_type: %hu d_name :%s\n", d->d_type, d->d_name);
	}



	// 2. 关闭目录
	closedir(dir);

	return 0;
}
