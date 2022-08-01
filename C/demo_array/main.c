#include <stdio.h>

void test() {
    // ��ʼ��������ַ���ʼ�� ���Ƽ�
    // char str[6] = {'h','e','l','l','o'};
    // str[0] = 'h' �� ASCII ֵ
    // ��ʼ�������ַ�������ʽ ��ʼ�� �Ƽ�
    char str[6] = "hello";

    // ����ַ�����
    for(int i=0; i<6; i++) {
        printf("%c", str[i]);
    }
    printf("\n-----------\n");

    // �ַ����� ����������� �Ƽ�
    printf("%s\n", str);

    printf("��0��Ԫ�صĵ�ַ��%p\n", &str[0]);
    printf("����ĵ�ַ��%p\n", str);
}

void compareArrayString() {
    char str1[] = {'h','e','h','e'}; // ����ַ���ʼ�� ϵͳ������� '\0'
    char str2[] = "hehe"; // ���ַ�����ʼ�� ϵͳ����ַ������ '\0'

    // �ռ��С
    printf("sizeof(str1)=%d\n", sizeof(str1)); //4
    printf("sizeof(str2)=%d\n", sizeof(str2)); //5

    // %s���������: ������ĵ�0��Ԫ�ؿ�ʼ���Ԫ����� ֱ������'\0'����
    printf("str1=##%s##\n", str1);
    printf("str2=##%s##\n", str2);
}

// ��ȡ���̵��ַ���������һ���ַ����� ���㹻��Ŀռ�
void charArray() {
    char buf[10] = "";
    printf("������һ���ַ���\n");

    // scanf �� %s ʹ��ʱ�����ո���������
    // scanf("%s", &buf); // ���ܻ�ȡ���ո���ַ�
    //gets(buf); // ��ȡ���ո���ַ��� ȱ�㣺����� buf �Ĵ�С ��������ڴ���Ⱦ

    // fgets�������ȿ��Դ��ո���ַ���Ҳ��֤buf ��Խ��
    // $ man fgets
    // s: ����ַ����Ŀռ��ַ, size:�ܹ���ȡ�ַ�������󳤶� size-1(�����ڲ���ȥ1)
    // char *fgets(char *s, int size, FILE *stream)
    printf("sizeof(buf)=%d\n", sizeof(buf));
    fgets(buf, sizeof(buf), stdin);
    // ����ַ�����
    for(int i=0; i<sizeof(buf); i++) {
        printf("%c", buf[i]);
    }

    printf("buf=%s\n", buf);
}

void arrayLevel2() {
    // & ȡ��ַ�����

    // & reference ���� <=> * dereference ������

    // &arr[0] �����õõ� arr, arr�����õõ� arr[0]

    // һά���������������һ��ָ�룬��ά�������������������ָ��
    int arr[3][4] = {{},{1,2,3,4},{}}; // int[4] arr[3]
    printf("arr = %p\n", arr);  // ��ʼ��ַ
    printf("&arr[0] = %p\n", &arr[0]);
    printf("arr = %p arr+1 = %p\n", arr, arr+1); // ���� 16

    printf("arr[0] = %p\n", arr[0]);
    printf("&arr[0][0] = %p\n", &arr[0][0]);
    printf("arr[0] = %p arr[0]+1 = %p\n", arr[0], arr[0]+1); // ���� 4

    printf("\n----------------------\n");

    printf("arr = %p\n", arr);
    printf("arr+1 = %p\n", arr+1); // ���� 16
    // ��arr������
    printf("*arr = %p\n", *arr);
    printf("*arr+1 = %p\n", *arr+1); // ���� 4

    // *(arr+1) ��ά����ĵ�2��Ԫ�ص�ַ
    // *(*(arr+1)+2) ��ά����ĵ�2��Ԫ�ص�ַ�ĵ�3��Ԫ�ص�ַ
     printf("&(*(*(arr+1)+2)) = %p\n", &(*(*(arr+1)+2))); // ���� 24
    printf("*(*(arr+1)+2) = %d\n", *(*(arr+1)+2)); // 3
}

int main(int argc, char *argv[])
{
    //test();
    // compareArrayString();
    // getchar();
    // charArray();
    arrayLevel2();
    return 0;
}
