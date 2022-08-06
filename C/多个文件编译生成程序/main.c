//
//  main.c
//  多个文件编译生成程序
//
//  Created by wovert on 2019/10/2.
//  Copyright © 2019 wovert. All rights reserved.
//

#include <stdio.h>
#include "encrypt.h"

int main(int argc, const char * argv[]) {
    char msg[80];
    while (fgets(msg, 80, stdin)) {
        encrypt(msg);
        printf("%s\n", msg);
    }
    return 0;
}
