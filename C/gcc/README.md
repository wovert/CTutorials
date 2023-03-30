# gcc

- 预处理：`gcc -E main.c -o main.i`

- 生成汇编：`gcc -S main.i -o main.s`

- 生成目标文件：`gcc -c main.s -o main.o`

- 生成可执行文件：`gcc main.o -o main`


## gcc parameter

- -g 调试信息
- -Wall 显示警告
- -Werror 警告显示为错误

- -On n=0-3 编译优化级别
- -D 编译时定义宏

