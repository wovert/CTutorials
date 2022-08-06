//
//  main.c
//  类型说明符
//
//  Created by wovert on 2019/10/1.
//  Copyright © 2019 wovert. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // int=4byte=-2^31~2^(31-1)
    int num = 17979878977;
    printf("num = %i\n", num);
    
    // long int = 8byte
    // li 或 lid 输出 long 类型的数据
//    long int num1 = 17979878977;
    long num1 = 17979878977;
    printf("num = %li\n", num1);
    
    // 64 bit 没有区别
    // 32 bit 下 long 占用4个字节，long long 占用8个字节, %lli or %lld
    long long num2 = 17979878977;
    printf("num = %lli, long long = %i, long = %i\n", num2, sizeof(num2), sizeof(num1));
    
    // short => %hi, %hd
    // signed => +-
    // unsigned => 0+ %u
    // unsigned short => %hu
    // unsigned int => %iu
    // sungined long => %lu
    
    
    return 0;
}
