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

struct Data {
    char c; // 1B
    int i; // 4B
};

static void test03() {
    printf("%lu\n", sizeof(struct Data)); // 8B
}


int main() {
    // test01();
    // test02();
    test03();
    
    return 0;
}

