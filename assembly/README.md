## 常见汇编指令

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