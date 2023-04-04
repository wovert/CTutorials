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

	newfd = 2;
	// 文件描述符2已经跟某个文件关联了，那么就先解除与该文件的关联，然后将该文件描述符与fd关联同一个文件
	newfd = dup2(fd, newfd);
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
