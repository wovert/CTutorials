//
//  arg.c
//  DemoC
//
//  Created by wovert on 18/12/18.
//  Copyright © 2018年 dev. All rights reserved.
//

#include <stdio.h>

// 不是C标准库，而是POSIX库。POXIS的目标是创建一套能够在所有主流OS上使用的函数
#include <unistd.h>

int main(int argc, char *argv[]) {
    char ch;
    char *engine_count;
    
    while ((ch = getopt(argc, argv, "ae:")) != EOF) { // 返回-1，也就是EOF
        printf("ch=%c\n", ch);
        switch(ch) {
            case 'e':
                engine_count = optarg; // -e选项参数
                break;
            case 'p':
                break;
            default:
                break;
        }
    }
    printf("optind=%d\n", optind);  // 4
    argc -= optind; // getopt()函数从命令行读取了几个选项
    printf("argc=%d\n", argc);      // 3
    argv += optind;
    
    for (int i=0; i<argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }

    
}
