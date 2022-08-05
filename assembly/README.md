## 常见汇编指令

## 汇编语言种类

- 8086汇编(16bit)
- x86汇编(32bit)
- x64汇编(64bit)
  - Intel(Windows)
  - AT&T(Mac)
- ARM汇编(嵌入式、移动设备)

## 寄存器

- 通用寄存器
  - 64Bit：RAX/RBX/RCX/RDX: 
  - 32Bit：EAX/EBX/ECX/EDX: 
  - 16Bit：AX/BX/CX/DX: 
	- AH:高字节
	- AL:低字节

## 汇编指令

| 助记符 | 说明 |
| ---- | ---- | 
| MOV | 传送（分配）数值 | 
| ADD | 两个数值相加 | 
| SUB | 从一个数值中减去另一个数值 | 
| MUL | 两个数值相乘 | 
| PUSH | 将 Stack 所指向的地址写入寄存器 | 
| RET | 用于终止当前函数的执行并返回 | 
| JMP | 跳转到一个新位置 | 
| CALL | 跳转到一个子程序  | 
| POP | 用于取出 Stack 最近写入的值 | 

- mov dest, src
  - 将src 的内容赋值给dest,  类似于dest=src
- [地址值]
  - 存放的是内存地址
- word 是2字节，dword 是 4字节(double world), qword是8字节(quad word)
- call 函数地址
  - 调用函数
- lea dest, [地址值]
  - load effect address
  - mov dest, src
  - 将地址值赋值给 dest, 类似于 dest = 地址值
- ret 函数返回
- xor op1, op2
  - 将op1和op2异或的结果赋值给op1, 类似于op1=op1^op2
- add op1, op2
  - op1=op1+op2
- sub op1, op2
   - op1=op1-op2
- inc op
  - increase: op=op+1
- dec op
- jmp 内存地址
  - CPU跳转到内存地址，并执行代码
  - 一般带条件跳转

- 汇编语言程序
```
.data               ;数据区
sum DWORD 0         ;定义名为sum的变量

.code               ;代码区
main PROC
mov eax,3           ;将数字3送入eax寄存器   ax:8bit, eax:32bit rax:64bit
add eax,4           ;eax寄存器加4

INVOKE ExitProcess,0    ;结束程序
main ENDP
```

- C 语言程序
```
int add(int a, int b) {
    return a + b;
}
int main() {
    return add(3, 4)
}

# 转换汇编语言
$ gcc -S demo.c
```

- 汇编语言程序

```
_add:
push %ebx
mov %eax, [%esp+8]
mov %ebx, [%esp+12]
add %eax, %ebx
pop %ebx
ret

_main:
push 3
push 4
call _add
add %esp, 8
ret
```

-C 语言嵌套汇编语言

```
#incldue <stdio.h>

int main() {
    // definition variables
    int a;
    int b;
    int c;

    __asm
    {
        mov a, 3 // 3值放在a对应内存的位置
        mov b, 4 // 4值放在b对应内存的位置
        mov eax, a // a内存的值放在eax寄存器
        add eax, b // eax和b相加，结果放在eax
        mov c, eax // eax的值放在c中
    }
    printf("%\d", c)
    return 0;
}
```