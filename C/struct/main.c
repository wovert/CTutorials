# include <stdio.h>
# include <string.h>

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

int main() {
    // test01();
    // test02();
    // test03();
    test04();
    
    return 0;
}

