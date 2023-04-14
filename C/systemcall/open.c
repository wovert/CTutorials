#include <stdio.h>
#include <string.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>

int main(void) {

  int fd = -1;

  // int open(const char *pathname, int flags, mode_t mode);
  // return success: 0, 1, 2, 3, ...
  // return faile: -1
 
  // O_RDONLY: open file by readonly type
  //fd = open("txt", O_RDONLY); // if not file return -1
  //fd = open("txt", O_RDONLY|O_CREAT, 0644); // if not file create file and fd
  fd = open("txt", O_RDONLY|O_CREAT|O_EXCL, 0644); // if not file create file return fd or exists file return -1

  if (-1 == fd) {
    perror("open");
    return 1;
  }

  printf("fd = %d\n", fd);

  // close file
  close(fd);

  return 0;



}
