#include <unistd.h> // read
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h> // EAGAIN


int main() {
  // /dev/ttyp 当前终端设备
  // 以不阻塞方式打开终端设备
  int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);

  char buf[10];
  int n;
  n = read(fd, buf, sizeof(buf));
  if (n < 0) {
    // 为非阻塞，但是没有数据可读，此时全局变量 errno 被设置为 EAGAIN
    if (errno != EAGAIN) {
      perror("read /dev/tty");
      return -1;
    }
    printf("没有数据\n");
  }
  return 0;

}
