# C++

> C with class

- 1. 语法
    - 1.1 通过反汇编窥探底层
- 2. Windows编程
    - 2.1 Windows API
    - 2.2 MFC(图形界面)
- 3. 项目实战
  - x86 汇编
  - 软件破解
  - 植物大战僵尸外挂

## C++应用领域

- 游戏（Cocos2d-X）、图像、多媒体、网络、嵌入式
- 数据库（Oracle、MySQL）、浏览器（Chrome），搜索引擎（ Google）
- 操作系统、驱动程序、编译器（Gcc、LLVM），编程语言(Swift)
- HPC(High Performance Computing)高新能计算
- iOS开发（Runtime, AsyncDisplayKit）
- Android 开发(NDK, fresco[匿名共享内存，Ashmem, Anomymus Shared Memory])
- Java(JNI)


https://isocpp.org/std/status
https://www.cnblogs.com/mjios/category/459066.html
https://www.cheatengine.org/downloads.php

- 逆向工程：IDA Pro
- Beyond Compare
- Intel 机器码的白皮书PDF

## 函数重载

> 采用 name mangling 或者 name decoration 技术
> C++编译器默认会对符号名（比如函数名）进行改编、修饰
> 重载时会生成多个不同的函数名，不同编译器（MSVC、g++）有不同的生成规则

- 规则
  - 函数名相同
  - 参数个数不同、参数类型不同、参数顺序不同

- 注意
  - 返回值类型与函数重载无关
  - 调用红函数时，实参的隐式类型转换可能会产生二义性

## 全局变量检测增强

- int a = 10; // 赋值，当作定义
- int a; // 没有赋值，当作声明 C++报错
- extern int a; // C++ 不报错


## struct 类型加强

- 定义变量时不需要是以哦那个struct
- 机构体内可以写函数

##  更严格的类型转换

- 不能隐式转换 `char *p = malloc(64);` 必须强制类型转换 `char *p = (char *)malloc(64);` 

## 三目运算符

- C 三目运算符返回的时右值
- C++ 三目运算符返回的时左值，时空间
  - int a = 10; int b = 20; ((a>b)?a:b) = 100;
  - 放在赋值操作符左边的时左值，放在右边的是右值


## C/C++混合开发

- 第三方框架/库：C语言的开源库


- ifndef, #define, #endif 来防止头文件的内容被重复包含
  - 受C/C++标准支持，不受编译器的任何限制
- progma once 可以防止整个文件的内容被重复包含
  - 有些编译器不支持#progma once(较老编译器不支持，如果GCC3.4版本之前)，兼容性不够好


