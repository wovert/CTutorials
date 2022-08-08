//
//  launch.c
//  makefile
//
//  Created by wovert on 2019/10/2.
//  Copyright © 2019 wovert. All rights reserved.
//

#include <stdio.h>
#include "launch.h"
#include "thruster.h"

int main(int argc, const char * argv[]) {
    thruster();
    func();
    return 0;
}
void func() {
    printf("launch file runnning func....\n");
}

