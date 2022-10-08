
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

int show_file_type_v1(struct stat *s) {
  switch(s->st_mode & S_IFMT) {
    case S_IFREG:
      printf("普通文件\n");
      break;
    case S_IFDIR:
      printf("目录文件\n");
      break;
    case S_IFCHR:
      printf("字符设备\n");
      break;
    case S_IFBLK:
      printf("快设备\n");
      break;
    case S_IFSOCK:
      printf("套接字文件\n");
      break;
    case S_IFIFO:
      printf("管道文件\n");
      break;
    case S_IFLNK:
      printf("符号链接文件\n");
      break;
    default:
      printf("未知文件\n");
  }
  return 1;
}

int main(int argc, char **argv) {

  // 获取文件类型
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
  show_file_type_v1(&s);
  show_file_type_v2(&s);


  return 0;
}
