# C++

## C++ History

- K&R C 1978
- C with Classes 1980
- C++ 98(V1.0)
- **C++ 11(V2.0)**

- C++ 语言
- C++ 标准库

> C with class

## C++

> 学习计算机程序设计的核心思想和编程范式（Paradigm）

- 面向对象
- 高性能
- 函数式
- 范式编程

学习抽象思维方式和逻辑方法论


## C++应用领域

- 界面（GUI）
- Job Opportunifies 工作
- 游戏（Cocos2d-X）、图像、多媒体、网络、嵌入式
- 数据库（Oracle、MySQL）、浏览器（Chrome），搜索引擎（ Google）
- 操作系统、驱动程序、编译器（Gcc、LLVM），编程语言(Swift)
- HPC(High Performance Computing)高新能计算
- iOS开发（Runtime, AsyncDisplayKit）
- Android 开发(NDK, fresco[匿名共享内存，Ashmem, Anomymus Shared Memory])
- Java(JNI)
- 云计算
- Libraries

- Microsoft
- Google
- Bloomberg(实时股票)
- MatLAB
- amazon.com
- oracle
- UBISOFT(游戏)
- UBer

https://isocpp.org/std/status
https://www.cnblogs.com/mjios/category/459066.html
https://www.cheatengine.org/downloads.php

- 逆向工程：IDA Pro
- Beyond Compare
- Intel 机器码的白皮书PDF

## 学习建议

1. 首选**官方资料**（手册、官网、文档）
2. **英文资料** > 中文资料
3. 掌握**验证知识点正确性**的方法（掌握汇编语言时最靠谱的验证知识点正确性的方式）
4. 学会**汇编语言**（掌握**代码的本质、破解、外挂**）

## 编程语言的发展

- 高级语言———编译———> 汇编语言<-反编译—————编译->机器语言——————>计算机
- 汇编语言与机器语言一一对应，每一条机器指令都有与之对应的汇编指令
- 汇编语言可以通过编译得到机器语言，机器语言可以通过反编译得到汇编语言
- **高级语言**可以通过**编译**得到**汇编语言/机器语言**，但**汇编语言/机器语言**几乎**不**可能**还原成高级语言**

```
	// 00842381  push        4
	cout << sizeof(int) << endl;
  cout << 4 << endl;


	28: 	struct Date {
	29: 		int year;
	30: 		int month;
	31: 		int day;
	32: 	};
	33: 	Date d = { 1,2,3 };
002623E8  mov         dword ptr [ebp-10h],1
002623EF  mov         dword ptr [ebp-0Ch],2
002623F6  mov         dword ptr [ebp-8],3
	34: 	int array[] = { 1,2,3 };
002623FD  mov         dword ptr [ebp-24h],1
00262404  mov         dword ptr [ebp-20h],2
0026240B  mov         dword ptr [ebp-1Ch],3
```

- 编译型语言（不依赖虚拟机）： C/C++/OC/Swift
- 脚本语言：Python/JS/PHP
- 编译型语言（依赖虚拟机）：Java/Ruby

## 编程的本质

> 寻找算法对应的最基础的代数结构 —— Alexxander Stepanov(STL之父)

- 编程->计算(Computing)
- 计算->建模(Modeling)
- 建模->抽象(abstraction)
- 抽象->范围(context)

在给定范围内，通过抽象和建模的方式来解决计算问题，就是编程

## 编程步骤

- IPO 算法模式：Input/Process/Output
- 分析
  - 要解决什么问题
  - 先决条件，边界条件，已知元素等
  - 例子：飞机起飞时最大安全重量
- 设计
  - 算法和步骤
- 实现
  - 编写，运行代码
  - 测试、调试、优化代码等

## 开发环境

- 必备软件
  - Virtual Box
  - MobaXTerm(Win)/Ternimal(Mac/Linux)
- VM
  - OS: Debian 10
  - 编译器：gcc/glibc/gdb, clang, lldb
  - 编辑器：emacs: Helm, TabNine
  - 其他：git, fish shell

```
-Y:图像界面
ssh -Y -p 3022 user@host
> emacs test.cpp &
> g++ test.cpp



预处理
> cpp test.cpp > test.i

编译
> g++ -g -S test.i

汇编
> as -o test.o test.s
> gcc -g -c test.c; objdump -d -M inter test.o > test.asm

链接
> ld -o test test.o ...


```

- [cppreference](https://zh.cppreference.com)
- [cplusplus](https://cplusplus.com/)
- [libstdc++](https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/)
- [GDB调试](https://yolinux.com/TUTORIALS/GDB-Commands.html)


## inline

> 内联函数

### 不会成为内联函数

- 存在过多的条件判断语句
- 函数体过大（50行）
- 对函数进行取址操作
- 不存在任何形式的循环语句

### 内联函数优点

- 有宏函数的效率，没有宏函数的缺点
- 类的成员函数默认加上 inline

## 函数默认参数

- 函数的默认参数后面的参数必须都是默认参数
- 函数的声明和实现不能同时有函数的默认参数
- 默认参数只能按照从右到左的顺序
- 如果函数同时有声明、实现，默认参数只能放在**函数声明中**
- 默认参数的值可以是常量、全局符号（全局变量、函数名）
- 函数重载、默认参数有能回产生冲突、二义性（建议优先使用默认参数）

- 占位参数在也有默认值
  - `void fun(int a, int=10){}`

## 函数重载

> 采用 name mangling 或者 name decoration 技术
> C++编译器默认会对符号名（比如函数名）进行改编、修饰
> 重载时会生成多个不同的函数名，不同编译器（MSVC、g++）有不同的生成规则

- 规则
  - 函数名相同
  - **参数个数不同、参数类型不同、参数顺序不同**

- 注意
  - **返回值类型与函数重载无关**
  - 调用宏函数时，实参的隐式类型转换可能会产生二义性


### 逆向工程：IDA Pro
- VS Debug模式：会有很多调试信息，生成可执行文件比较臃肿
- VS Release模式：去除调试信息，生成可执行文件比较精简、高效


## extern C

> 被`extern C`修饰的代码会按照 **C** 语言的方式**编译**
> 如果**函数**同时有**声明和实现**，必须**函数声明被extern "C" 修饰**，函数实现可以不修饰

```
extern "C" void func() {
  ...
}
extern "C" {
  void func() {

  }
  void func2() {}
}
```

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


## C/C++ const

1. C语言的const修饰的变量在全局区域声明并初始化之后不能修改，作为局部变量可以间接的修改内容;
2. C语言的const修饰的全局变量具有外部链接属性； 
3. C++在全局变量在编译阶段直接替换为具体常量值；如果使用volatile 禁止优化，则在编译阶段不替换常量值；
4. C++语言的const修饰ide变量有时有空间（volatile），有时没有空间(发生常量折叠，且没有对变量进行取址操作)
5. C++语言的const修饰的全局变量具有内部链接属性（原因：命名冲突）; 可以加 extern 就变为外部链接属性；

### C++编译器不能优化

1. 自定义数据类型；
2. 用变量给const修饰的局部变量赋值；
3. 编译器是编译阶段来优化数据；

## C/C++混合开发

- 第三方框架/库：C语言的开源库

- ifndef, #define, #endif 来防止头文件的内容被重复包含
  - 受C/C++标准支持，不受编译器的任何限制
- progma once 可以防止整个文件的内容被重复包含
  - 有些编译器不支持#progma once(较老编译器不支持，如果GCC3.4版本之前)，兼容性不够好


## const

  1. const int data =10; // data先放入符号表
  2. 对data取地址系统给data开辟空间；
  3. const int a = b;// b 是变量名 系统直接给a开辟空间 而不放入符号表;
  4. const 修饰自定义数据 系统为自定义数据开辟空间；

## define

  ```
  namespae A {
    #define MY_A 200
  }

  // MY_A 属于文件，不属于A
  count << "MY_A=" << MY_A <<endl;
  ```

## 引用

> 空间取别名

引用的本质是常量指针

- &是标记作用；
- 引用创建时，必须初始化
- 初始化之后不能改变的指向空间
- 必须引用一块合法的内存空间


```
int a  = 10;
int &b = a; // 给a的空间取别名叫b，编译器内部为  int * const b = &a;
printf("b=%d\n", b);

void func(int &a) {
	a = 200;
}

func(int a);
printf("a=%d\n", b); // 200
```

- 引用作为函数的返回值
  - 不要返回局部变量的引用
  - static声明的局部变量可以返回引用
  - func() = 100; 如果函数当左值，那么该函数必须返回引用

### 数组的引用

```
int arr[] = {1,2,3};

// 1 定义三个整形元素的数组
typedef int(MY_ARR)[3];
// 建立引用 int &b=a;
MY_ARR &arrRef = arr;

// 2 直接定义引用
int(&arrRef2)5] = arr; // int &b=a


// 3 建立引用数组类型
typedef int(&MY_ARR3)[5];
MY_ARR3 arrRef3 = arr;
```

### 常量引用

- 字面量不能赋给引用，但是可以赋给const引用
- const修饰的引用，不能修改


- 字面量不能赋给引用
  - int &ref = 100;

- 一个字面量赋给常量引用
- const修饰的有你用赋给字面量
- const int &ref = 100; 

- 以上代码编译器变为以下代码
- int temp = 200;
- const int &ret = temp;
- ret = 200; // 不能通过ret修改值

### 指针的引用


## C和C++的区别

- C语言的结构体不能写函数，C++可以
- 结构体定义变量时，C++不需要加struct关键字
- 更佳严格的类型检查
- const修饰的变量，C++有时没有内存，C语言的都有内存
- 三目运算符返回的值不一样
- 引用和C语言的指针功能一样

## 混合编译步骤

- main.ccp/func.c/fun.h

1. gcc -c fun.c -o fun.o 或者 g++ -c data.cpp -o data.o
2. g++ main.cpp fun.o -o main

## 类

### 类定义在头文件 成员函数在cpp文件中实现

## 结构体和类的区别

1. 结构体默认权限是共有的，类的默认权限是私有的

### static

- 静态变量，在**编译阶段分配空间**，对象还没有创建时，就已经分配空间。
- 静态成员变量必须在**类中声明**，在**类外定义**

## vector

> 面向对象方式的动态数组


## 友元

> 是特权函数，可以访问私有成员


### 声明为友元

- 全局函数
- 成员函数
- 类声明

## 查看对象模型

1. 打开VS 2017 开发人员命令提示符
2. 切换到文件所在目录 cd 
3. cl /d1 reportSingleClassLayout类名 文件名全程 