#include <stdio.h>
#include <string.h>
void print_reverse(char *s);

int main() {
  char *title = "This is Alice";
  if (strstr(title, "Alice")) {
    printf("Alice is has.%i\n",strlen("Alice中"));
  }
  print_reverse("Alice");
  fprintf(stdout,"Hello World");
  fprintf(stderr,"error");
  return 0;
}
void print_reverse(char *s) {
  int len = strlen(s);
  char *t = s + len - 1;
  while (t >= s) {
    printf("%c", *t);
    t = t - 1;
  }
  puts("");
}