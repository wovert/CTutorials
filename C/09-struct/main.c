# include <stdio.h>
# include <string.h>
#include <malloc.h>

// ָ��������� min(8, DATA1.b) = 4
#pragma pack(8)

// Student �ǽṹ��������
struct Student {
    int sid;
    char name[1024];
    int age;
};

void s1(struct Student);
void s2(struct Student *);


void s1(struct Student stu) {
    printf("%p\n", &stu);
}

static void test01() {
  // �ṹ���ʼ��
  struct Student st = {1000, "����", 20};
  printf("&st=%p: st.sid=%d st.name=%s st.age=%d\n", &st, st.sid, st.name, st.age);

  // ʹ�ýṹ���ַ���ʳ�Ա
  printf("&st=%p: (&st)->sid=%d (&st)->name=%s (&st)->age=%d\n", &st, (&st)->sid, (&st)->name, (&st)->age);
  printf("&st.sid=%p &st.name=%p &st.age=%p\n", &st.sid, &st.name, &st.age);
  struct Student st2 = {.age=23, .sid=100};
  printf("sizeof(st2.name)/sizeof(st2.name[0])=%d\n", sizeof(st2.name)/sizeof(st2.name[0]));
  printf("sizeof(st2.name)/sizeof(st2.name[0])=%d\n", strlen(st2.name));


  strcpy_s(st2.name,  sizeof(st2.name)/sizeof(st2.name[0]), "����");
//  strcpy(st2.name, "����");
  printf("&st2=%p: st2.sid=%d st2.name=%s st2.age=%d\n", &st2, st2.sid, st2.name, st2.age);
}

void memcpy_str(struct Student *, struct Student *);

void memcpy_str(struct Student *x, struct Student *y) {
  memset( x , 0 ,sizeof(x));
  memcpy(x, y, sizeof(x)); // �����ֽڵ�λ
}

typedef struct {
  int id;
  char *name;
  char desc[1024];
} Tea;

static void test02() {

    struct Student st = {1000, "����", 20};
    struct Student st2;

    // 1. ��������
//    memcpy_str(&st2, &st);

    // 2. ��������
//    st2.sid = st.sid;
//    st2.age = st.age;
//    strcpy_s(st2.name, sizeof(st.name)/sizeof(st.name[0]), st.name);

    // 3. �������� ��ͬ���Ϳ��Ը�ֵ
    st2 = st;

  printf("sid=%d name=%s age=%d\n", st.sid, st.name, st.age);
  printf("sid=%d name=%s age=%d\n", st2.sid, st2.name, st2.age);

//    struct Student *pst = &st;
    struct Student *pst = malloc(sizeof(struct Student));
    pst->sid = 99;
    
    printf("pst��ַ=%p\n", pst);
    printf("pst���׸���Ա��ַ=%p, ֵ=%d\n", &pst->sid, pst->sid);
    
    s1(st);

    printf("------------------\n");

    Tea *p = (Tea *)malloc(sizeof(Tea));
    p->id = 100;
    p->name = "���"; // ok: ����ٳ�������name �ڶѿռ����ó������ĵ�ַ
    char n[1024] = "����";


    p->name = (char *)malloc(128);
    // error: p->name ��Ұָ�룬��֪��ָ��������Բ��ܸ�ֵ����
    // �����������������ڴ�ռ�
    strcpy_s(p->name, 128, "�ײ�");

    printf("p->id=%d\n", p->id);
    printf("p->name=%s\n", p->name);


    // �ͷ��ڴ�
    free(p->name);
    free(p);

}

typedef struct {
    char c; // 1B
    int i; // 4B
} Data; // Data �ṹ�������

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
    // ����p����20
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

//  �������
static void test05() {
	//printf("%d\n", sizeof(DATA1)); // value(2) = 8
	//printf("%d\n", sizeof(DATA1)); // value(1) = 7
	printf("%d\n", sizeof(DATA1)); // value(8) = 4 = 12
}


typedef struct {
	// ����λ�� ����ѹ����ѹ����λ�� ���ܳ�����Ա�����С��
	// ��λ��ʼ
	unsigned char a : 2;
	unsigned char : 4; //  �������λ�Σ�ռ2λ��
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
//     test01();
     test02();
    // test03();
    //test04();
	//test05();
//	test06();
    
    return 0;
}

