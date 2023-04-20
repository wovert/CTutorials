#include <stdio.h>
#include <string.h>

// fopen: Linux C Library io function
int main() {
  FILE *fp = NULL;
  char buf[128] = "";
  int i = 0;

  // readable return FILE struct address or return NULL
  fp = fopen("./fopen.txt", "r");
  

  // Check exists a.txt file and readable
  if (fp == NULL) {
    perror("fopen");
    return -1;
  }

  //char c;

  // EOF == -1
//  while ((c = fgetc(fp)) != EOF) {
//    buf[i] = c;
//    printf("%c=%d\n", buf[i], buf[i]);
//    i++;
//  }

  do {
    buf[i] = fgetc(fp); // read one charactor
    printf("%c", buf[i]);
    i++;
  } while(!feof(fp));
  printf("end do while\n");

  printf("buf=%s,strlen(buf)=%ld sizeof(buf)=%ld\n", buf,strlen(buf), sizeof(buf));

  // close file
  fclose(fp);
  
  return 0;
}
