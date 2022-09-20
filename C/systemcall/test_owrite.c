#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(void) {

	int fd = -1;
	// readonly open file
	//fd = open("txt", O_WRONLY | O_CREAT | O_EXCL, 0644);
	fd = open("txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (-1 == fd) {
		perror("open");
		return 1;
	}

	printf("fd = %d\n", fd);

	// close file
	close(fd);

	return 0;
}
