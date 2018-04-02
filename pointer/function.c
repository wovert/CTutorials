# include <stdio.h>

void change(int *p);

int main() {
  
  int i = 10;
  
  printf("i=%d, i addr=%p\n", i, &i);
  
  change(&i);

  printf("i=%d, i addr=%p\n", i, &i);

  return 0;
}

void change(int *p) {
  *p = 100;
}