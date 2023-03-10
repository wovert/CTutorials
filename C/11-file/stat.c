#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

  struct stat buf;
  int ret = 0;
  ret = stat("../a.txt", &buf);
  if (ret < 0) {
    printf("file not found\n");
  }
  printf("file size %d\n", buf.st_size);
  printf("file type %u\n", buf.st_rdev);

  return 0;
}