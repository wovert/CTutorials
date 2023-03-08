# include <stdio.h>
# include <string.h>

// 指定对齐规则 min(8, DATA1.b) = 4
#pragma pack(8)

struct Student {
    int sid;
    char *name;
    int age;
};

void s1(struct Student);
void s2(struct Student *);


void s1(struct Student stu) {
    printf("%p\n", &stu);
}

static void test01() {
    struct Student st = {1000, "张三", 20};
    //strcpy(st.name, "李四");
    printf("%p: %d %s %d\n", &st, st.sid, st.name, st.age);
    printf("%p %p %p\n", &st.sid, &st.name, &st.age);
}

static void test02() {

    struct Student st = {1000, "张三", 20};
    struct Student *pst = &st;
    pst->sid = 99;
    
    printf("%p\n", pst);
    printf("%p\n", &pst->sid);
    
    s1(st);
}

typedef struct {
    char c; // 1B
    int i; // 4B
} Data;

typedef struct {
    int a;
    char b;
    short c;
    char d;
} DATA;

typedef struct {
    char c;
    short s;
    int i;
    long l;
    char cc;
} A;

typedef struct {
    char c;
    short s;
    A a;
    int i;
}B;

typedef struct {
    char c;
    short s;
    int i;
    char cc;
} C;

typedef struct {
    char c;
    short s;
    long l;
    C cs;
    int i;
}D;

static void test03() {
    printf("%lu\n", sizeof(Data)); // 8B
    Data d;
    printf("&d.c = %lu\n", (unsigned long)&d.c);
    printf("&d.i = %lu\n", (unsigned long)&d.i);
    
    printf("---------\n");

    DATA data;
    printf("&data.a = %lu\n", (unsigned long)&data.a);
    printf("&data.b = %lu\n", (unsigned long)&data.b);
    printf("&data.c = %lu\n", (unsigned long)&data.c);
    printf("&data.d = %lu\n", (unsigned long)&data.d);
    printf("sizeof(data) = %lu\n", sizeof(data));

    printf("---------\n");

    B b;
    printf("&b.c = %lu\n", (unsigned long)&b.c);
    printf("&b.s = %lu\n", (unsigned long)&b.s);
    printf("&b.a.c = %lu\n", (unsigned long)&b.a.c);
    printf("&b.a.s = %lu\n", (unsigned long)&b.a.s);
    printf("&b.a.i = %lu\n", (unsigned long)&b.a.i);
    printf("&b.a.l = %lu\n", (unsigned long)&b.a.l);
    printf("&b.a.cc = %lu\n", (unsigned long)&b.a.cc);
    printf("&b.i = %lu\n", (unsigned long)&b.i);
    printf("sizeof(b) = %lu\n", sizeof(b));

    /*
    c       x       s       s       x       x       x       x
    a.c     x       a.s     a.s     a.i     a.i     a.i     a.i
    a.l     a.l     a.l     a.l     a.l     a.l     a.l     a.l
    a.cc    x       x       x       x       x       x       x
    i       i       i       i
    */

    printf("---------\n");

    D dd;
    printf("&dd.c = %lu\n", (unsigned long)&dd.c);
    printf("&dd.s = %lu\n", (unsigned long)&dd.s);
    printf("&dd.l = %lu\n", (unsigned long)&dd.l);
    printf("&dd.cs.c = %lu\n", (unsigned long)&dd.cs.c);
    printf("&dd.cs.s = %lu\n", (unsigned long)&dd.cs.s);
    printf("&dd.cs.i = %lu\n", (unsigned long)&dd.cs.i);
    printf("&dd.cs.cc = %lu\n", (unsigned long)&dd.cs.cc);
    printf("&dd.i = %lu\n", (unsigned long)&dd.i);
    printf("sizeof(dd) = %lu\n", sizeof(dd));

    /*
        c       *       s       s       *       *       *       *
        l       l       l       l       l       l       l       l
        cs.c    *      cs.s    cs.s    cs.i    cs.i    cs.i    cs.i
        cs.cc   *       *       *       i       i       i       i    
    */


}


static void test04() {
    typedef struct {
        char c;
        int i;
        short s;
    } DATA;

    DATA data = {'a', 100, 20};
    char *p = &data;
    printf("c = %hd\n", data.c);
    // 借助p访问20
    printf("*(p+0) = %hd\n", *(short *)(p+0));
    printf("*(p+1) = %hd\n", *(short *)(p+1));
    printf("*(p+2) = %hd\n", *(short *)(p+2));
    printf("*(p+3) = %hd\n", *(short *)(p+3));
    printf("*(p+4) = %d\n", *(int *)(p+4));
    printf("*(p+5) = %hd\n", *(short *)(p+5));
    printf("*(p+6) = %hd\n", *(short *)(p+6));
    printf("*(p+7) = %hd\n", *(short *)(p+7));
    printf("*(p+8) = %hd\n", *(short *)(p+8));
}

typedef struct {
	char a; // 2
	int b; // 4
	short c; // 2
} DATA1;

//  对齐规则
static void test05() {
	//printf("%d\n", sizeof(DATA1)); // value(2) = 8
	//printf("%d\n", sizeof(DATA1)); // value(1) = 7
	printf("%d\n", sizeof(DATA1)); // value(8) = 4 = 12
}


typedef struct {
	// 响铃位域 可以压缩（压缩的位数 不能超过成员自身大小）
	// 低位开始
	unsigned char a : 2;
	unsigned char : 4; //  无意义的位段（占2位）
	unsigned char b : 2;
} BIT_DATA;

static void test06() {
	BIT_DATA d;
	memset(&d, 0, 1);
	printf("%d\n", sizeof(d)); // 1B
	d.a = 0; //
	d.b = 3;
	printf("%u\n", d.a); // 2
	printf("%u\n", *(unsigned char *)&d); // 1100 0000 // 2^6+2^7=64+128=192
}

int main() {
    // test01();
    // test02();
    // test03();
    //test04();
	//test05();
	test06();
    
    return 0;
}

