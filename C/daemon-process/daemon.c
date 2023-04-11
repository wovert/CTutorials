#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>


#define SIZE 1024

// 创建守护进程
int main() {
 
  char file_name[SIZE];	
  int ret = -1;
  pid_t pid = -1;
  time_t t = -1; // long int
  struct tm *pT = NULL;
  int year = 0;
  int month = 0;
  int day = 0;
  int hour = 0;
  int minute = 0;
  int second = 0;

  // 1 创建子进程 退出父进程
  pid = fork();
  if (-1 == pid) {
    perror("fork");
    return 1;
  }
  // 退出父进程
  if (pid > 0) {
    exit(0);
  }

  // 2 创建新的会话 完全脱离控制终端
  pid = setsid();
  if (-1 == pid) {
    perror("setid");
    return 1;
  }

  // 3 改变当前工作目录, 防止挂在目录移除
   ret = chdir("/");
   if (-1 == ret) {
     perror("chdir");
     return 1;
   }

  // 4 设置权限掩码
  umask(0);

  // 5 关闭文件描述符
  close(STDIN_FILENO); // stdin -- FILE *
  close(STDOUT_FILENO); // stdin -- FILE *
  close(STDERR_FILENO); // stdin -- FILE *

  // 6 执行核心的任务
  // 每个一秒钟输出当前时间到/tmp/time.log 文件中
  while(1) {
    // 以秒单位的时间戳
    t = time(NULL);
    if (-1 == t) {
      perror("time");
      return 1;
    } 

    // 格式化日期
    pT = localtime(&t);
    if (NULL == pT) {
      printf("localtime failed.\n");
      return 1;
    }

    year = pT->tm_year + 1900;
    month = pT->tm_mon + 1;
    day = pT->tm_mday;
    hour = pT->tm_hour;
    minute = pT->tm_min;
    second = pT->tm_sec;

    // 转化为文件名
    memset(file_name, 0, SIZE);
    sprintf(file_name, "%s%04d%02d%02d%02d%02d%02d.log", "touch /tmp/log/",year, month, day, hour, minute, second);
    
    system(file_name);
    
    //system("date >> /tmp/time.log");
    sleep(1);
    
  }
  return 0;
}
