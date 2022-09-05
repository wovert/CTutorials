#include <stdio.h>

extern int global_scope_var = 1000;
void scope() {
	//static global_scope_var;
	int global_scope_var = 1111;
	global_scope_var = global_scope_var;
	printf("%d\n",  global_scope_var);
}