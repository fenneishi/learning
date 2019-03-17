#include<stdio.h>
#include<stdlib.h>


void f1(int A[][3]);
void f2(int (*A)[3]);

int main(void)
{
    int A[3][3];
    f1(A);
    f2(A);
    return 0;
}

void f1(int A[][3])
{
    printf("the size of A is %zd",sizeof(A));
}

void f2(int (*A)[3])
{
    printf("the size of A is %zd",sizeof(A));
}

// 传递二维数组比较标准的两种写法
