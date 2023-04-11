#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 128

int main(void) {

	int fd = -1;
	int newfd = -1;


	fd = open("txt", O_RDWR | O_CREAT, 0644);
	if (-1 == fd) {
		perror("open");
		return 1;
	}

	printf("fd=%d\n", fd);

	// 文件描述符复制
	newfd = dup(fd);
	if (-1 == newfd) {
	  perror("dup");
	  return 1;
	}

	printf("newfd=%d\n", newfd);

	write(fd, "abcdefg", 7);
	write(newfd, "1234567", 7);



	close(fd);
	close(newfd);

	return 0;
}
