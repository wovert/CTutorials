#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 128

int main(void) {

	int res = -1;

	struct stat s;

	res = stat("txt", &s);
	if (-1 == res) {
		perror("stat");
		return 1;
	}

	printf("st_dev: %lu\n", s.st_dev);
	printf("st_ino: %ld\n", s.st_ino);
	printf("st_nlink: %lu\n", s.st_nlink);
	printf("st_uid: %d\n", s.st_uid);
	printf("st_gid: %d\n", s.st_gid);
	printf("st_size: %ld\n", s.st_size);

	close(res);

	return 0;
}
