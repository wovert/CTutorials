
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// 显示文件类型
int show_file_type_v2(struct stat *s) {
  if (S_ISREG(s->st_mode)) {
    printf("Is a regular file\n");
  }
  if (S_ISDIR(s->st_mode)) {
    printf("Is a directory \n");
  }
  if (S_ISCHR(s->st_mode)) {
    printf("Is a character \n");
  }
  if (S_ISLNK(s->st_mode)) {
    printf("Is a link \n");
  }
  if (S_ISBLK(s->st_mode)) {
    printf("Is a block \n");
  }
  if (S_ISFIFO(s->st_mode)) {
    printf("Is a fifo \n");
  }
  if (S_ISSOCK(s->st_mode)) {
    printf("Is a socket \n");
  }
  return 1;
}

int show_promission_v1(struct stat *s) {
  // 文件所属者读权限
  if (s->st_mode & S_IRUSR) {
	  printf("r");
  } else {
    printf("-");
  }

  // 文件所数者写权限
  if (s->st_mode & S_IWUSR) {
	  printf("w");
  } else {
    printf("-");
  }
  if (s->st_mode & S_IXUSR) {
	  printf("x");
  } else {
    printf("-");
  }

  if (s->st_mode & S_IRGRP) {
          printf("r");
  } else {
    printf("-");
  }

  // 文件所数者写权限
  if (s->st_mode & S_IWGRP) {
          printf("w");
  } else {
    printf("-");
  }
  if (s->st_mode & S_IXGRP) {
          printf("x");
  } else {
    printf("-");
  }

  if (s->st_mode & S_IROTH) {
          printf("r");
  } else {
    printf("-");
  }

  // 文件所数者写权限
  if (s->st_mode & S_IWOTH) {
          printf("w");
  } else {
    printf("-");
  }
  if (s->st_mode & S_IXOTH) {
          printf("x");
  } else {
    printf("-");
  }

  return 1;
}

int main(int argc, char **argv) {

  // 文件权限
  int res = -1;
  struct stat s;

  // 容错判断
  if (2 != argc) {
    printf("usage ./a.out filename\n");
    return 1;
  }

  // 获取文件信息
  res = stat(argv[1], &s);
  if (-1 == res) {
    perror("stat");
    return 1;
  }

  // 显示文件类型
  show_promission_v1(&s);
  //show_file_type_v2(&s);


  return 0;
}
