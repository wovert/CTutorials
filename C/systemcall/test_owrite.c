#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(void) {

	int fd = -1;
	int res = -1;

	char *str = "hello world";
	// readonly open file
	// O_EXCL: if file exists show error
	// O_CREAT: if file not exists create file
	// O_TRUNC: if file exists empty content
	//fd = open("txt", O_WRONLY | O_CREAT | O_EXCL, 0644);
	//fd = open("txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	fd = open("txt", O_WRONLY | O_CREAT, 0644);
	if (-1 == fd) {
		perror("open");
		return 1;
	}

	printf("fd = %d\n", fd);

	// write content
	res = write(fd, str, strlen(str));

	if (res == -1) {
		perror("write");
		close(fd);
		return 1;
	}

	printf("write len:%d\n", res);


	// close file
	close(fd);

	return 0;
}
