#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void FUNC(int, int);

void func(int a, int b) {
  printf("a=%d b=%d\n", a, b);
}

int test(int a, int b, int (*callback)(int)) {
  int result = a + b;
  callback(result);
}

int call(int result) {
  printf("result=%d\n", result);
}

int main() {

  FUNC *pFunc = func;
  // pFunc = *(&pFunc) = *pFunc = &func
  pFunc(20, 30);
  (&func)(20, 30);
  (*(&pFunc))(20, 30);
  (*pFunc)(20, 30);

  printf("pFunc=%p\n", pFunc);
  printf("(&func)=%p\n", &func);
  printf("*(&pFunc)=%p\n", *(&pFunc));
  printf("*pFunc=%p\n", *pFunc);

  test(30, 40, call);

  return 0;
}