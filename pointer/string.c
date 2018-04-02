#include <stdio.h>

void fortune_cookie(char msg[]) {
  printf("Message reads: %s\n", msg);
  printf("msg occupies %p bytes\n", msg);
  printf("msg occupies %i bytes\n", sizeof(msg));
}

int main() {
  char quote[] = "Cookies make you fat";
  printf("msg occupies %p bytes\n", quote);
  fortune_cookie(quote);  
  return 0;
}