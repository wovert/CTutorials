# Library


## 静态连接

静态编译连接：`gcc -static main.c -o main`

## 动态连接

> 系统默认动态编译连接


```
$ gcc -c add.c -o add.o
$ gcc -c sub.c -o sub.o
$ gcc -c mul.c -o mul.o
$ gcc -c div.c -o div.o
$ gcc main.c add.o sub.o mul.o div.o -o main
$ ./main



制作静态库
$ ar -rcs libmath.a add.o sub.o mul.o div.o


静态编译连接 
-i 指定头文件目录 -L: 指定库目录 -l: 连接库名字

$ cp math_static -rf math_static_library
$ cd math_static_library
$ rm -rf *.o *.c
$ cd ../
$ vim math_static.c
  #include "add.h"
  ...
  int main() {...}
$ gcc math_static.c -I./math_static_library -L./math_static_library -lmath -o math_s
$ ./math_s

```


## 动态库制作

```
-fPIC 创建与地址无关的编译程序
$ gcc -fPIC -c add.c
$ gcc -fPIC -c sub.c
$ gcc -fPIC -c mul.c
$ gcc -fPIC -c div.c

生成共享库
$ gcc --shared add.o sub.o mul.o div.o -o libmath.so


查看库对应的函数
$ nm libmath.so | grep add

动态编译链接

// 1
$ cp libmath.so /usr/local/lib
$ gcc math_dynamic.c -I./math_dynamic -lmath

// 2
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/math_dynamic

// 3
$ vim /etc/ld.so.conf
添加动态库目录添加到新行

$ sudo ldconfig -v

// 4
$ sudo ln -s /home/math_dynamic/libmath.so /lib/libmath.so

查看可执行文件依赖库
$ ldd a.out
```
