#include <stdio.h>

int main() {
  char s[] = "hello World";
  char *t = s;
  printf("s is %i\n",sizeof(s)); // 12 
  printf("t is %i\n",sizeof(t)); // 4
  printf("s==&s is %p==%p\n", s, &s);
  printf("====================\n"); // 4

  int a[] = {1,2,3,4,5};
  int *b = a;
  int *c = a;

  printf("a is %i\n",sizeof(a)); // 5 
  printf("b is %i\n",sizeof(b)); // 4
  printf("c is %i\n",sizeof(c)); // 4
  printf("====================\n");

  // a[1] == *(a+1) == *(1+a) == *(1+a) == 1[a]
  a[1] = 10;
  printf("a[1] is %i,%p\n", a[1], a+1); // 10 
  printf("====================\n");

  *(a+1) = 20;
  printf("a[1] is %i,%p\n", a[1], a+1); // 30
  printf("*(a+1) is %i,%p\n", *(a+1), a+1); // 20 
  printf("====================\n");

  *(1+a) = 30;
  printf("a[1] is %i,%p\n", a[1], 1+a); // 30
  printf("*(a+1) is %i,%p\n", *(a+1), 1+a); // 30
  printf("*(1+a) is %i,%p\n", *(1+a), 1+a); // 30 
  printf("====================\n");

  1[a] = 40;
  printf("1[a] is %i,%p\n", 1[a], 1+a); // 40 
  printf("a[1] is %i,%p\n", a[1], 1+a); // 40
  printf("*(a+1) is %i,%p\n", *(a+1), 1+a); // 40
  printf("*(1+a) is %i,%p\n", *(1+a), 1+a); // 40 
  printf("====================\n");

  printf("*a is %i,%p\n", *(a), a); // 1 

  return 0;
}