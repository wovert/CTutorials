#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define SIZE 128

int main(void) {

	int fd = -1;
	int res = -1;

	char buf[SIZE];

	// readonly open file
	fd = open("txt", O_RDONLY);
	if (-1 == fd) {
		perror("open");
		return 1;
	}

	printf("fd = %d\n", fd);

	memset(buf, 0, SIZE);
	res = read(fd, buf, SIZE);
	

	if (res == -1) {
		perror("read");
		close(fd);
		return 1;
	}

	printf("read len:%d %s\n", res, buf);


	// close file
	close(fd);

	return 0;
}
