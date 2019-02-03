//
//  main.c
//  function
//
//  Created by wovert on 2019/2/3.
//  Copyright © 2019 weiming. All rights reserved.
//
int sum(int, int);

#include <stdio.h>

int main(int argc, const char * argv[]) {
    printf("argc= %i\n", argc);
    printf("argv[0]=%s\n", argv[0]);
    printf("argv[1]=%s\n", argv[1]);
    
    int a = 10;
    int b = 20;
    int result = sum(a, b);
    
    printf("result=%i\n", result);
    return 0;
}

int sum(int a, int b) {
    return a + b;
}
