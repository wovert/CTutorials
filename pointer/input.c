#include <stdio.h>

int main() {
  char first_name[20];
  char last_name[20];
  scanf("%19s %19s", first_name, last_name);
  printf("First name is %s, last name is %s\n",first_name, last_name);
  return 0;
}