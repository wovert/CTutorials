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


  // 1. 打开文件
  fd = open("lseek.txt", O_RDWR | O_CREAT, 0644);
  if (-1 == fd) {
    perror("open");
    return 1;
  }

  printf("fd = %d\n", fd);

	
  // lseek
  write(fd, "ABCDEFG", 7);

  // SEEK_SET 文件开头偏移32个字节
  res = lseek(fd, 32, SEEK_SET);

  if (res == -1) {
    perror("lseek");
    close(fd);
    return 1;
  }

	
  write(fd, "1234567890", 10);

  // reset offset seek init start
  lseek(fd, 0, SEEK_SET);
  //lseek(fd, 32, SEEK_SET);

  memset(buf, 0, SIZE);


  read(fd, buf, SIZE);

  printf("read res=%d  buf=%s\n", res, buf);



  // close file
  close(fd);

  return 0;
}
