# include <stdio.h>
# include <string.h>

void s1(struct Student);
void s2(struct Student *);

struct Student {
  int sid;
  char *name;
  int age;
};

int main() {
  struct Student st = {1000, "张三", 20};
  //strcpy(st.name, "李四");
  printf("%p: %d %s %d\n", &st, st.sid, st.name, st.age);
  printf("%p %p %p\n", &st.sid, &st.name, &st.age);

  struct Student *pst = &st;
  pst->sid = 99; 

  printf("%p\n", pst);
  printf("%p\n", &pst->sid);

  s1(st);

  return 0;
}

void s1(struct Student stu) {
  printf("%p\n", &stu);
}



