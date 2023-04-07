#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>


int main() {

  char ip[] = "192.168.1.110";
  
  unsigned dest = 0;
  
  // AF_INET: IPV4, AF_INET6: IPV6
  // char[] to network bye order
  int res = inet_pton(AF_INET, ip, &dest);
  if (1 != res) {
    printf("inet_pton  failed\n");
    return 1;
  }
  printf("dest=%d\n", dest);
  unsigned char *p2 = (unsigned char *)&dest;
  printf("%d.%d.%d.%d\n", *p2, *(p2+1), *(p2+2), *(p2+3));



  char nowip[16] = "";
  const char *ipName = inet_ntop(AF_INET, &dest, nowip, 16);
  printf("ipName=%s\n", ipName);

  return 0;
}
