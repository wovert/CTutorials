#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(void) {

	int fd = -1;
	// readonly open file
	fd = open("txt", O_RDONLY);
	if (-1 == fd) {
		perror("open");
		return 1;
	}

	printf("fd = %d\n", fd);

	// close file
	close(fd);

	return 0;
}
