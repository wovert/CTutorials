#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>


int main() {

  char buf[4] = {192,16,210,19};
  int num = *(int *)buf;
  int sum = htonl(num);
  unsigned char *p = (char *)&sum;
  printf("%d %d %d %d\n", *p, *(p+1), *(p+2), *(p+3));

  unsigned short a = 0x0102;
  unsigned short b = htons(a);

  printf("%x\n", b);

  char buf2[4] = {110,1,168,192};
  int num2 = *(int *)buf2;
  int sum2 = ntohl(num2);
  unsigned char *p2 = (char *)&sum2;
  printf("%d.%d.%d.%d\n", *p2, *(p2+1), *(p2+2), *(p2+3));

  return 0;
}
