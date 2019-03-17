#include<stdio.h>

int a=10;
int b=a;//是可以用全局变量初始化的



class A 
{
    int i;
public:
    void f(void);
    void f(int a);
};

class B :public A
{
    int a;
    int b;
public:
    void f(void);
    void f(double);
    void f(int);
};

void A::f(void)
{
    printf("A:f(     )\n");
}
void A::f(int a)
{
    printf("A:f(int a)\n");
}

void B::f(void)
{
    printf("B:f(     )\n");
}
void B::f(double a)
{
    printf("B:f(double)\n");
}
void B::f(int a)
{
    printf("B:f(int)\n");
}

int main(void)
{
    A a;
    B b;
    A *p=NULL;
    A &r=a;
    A &R=r;//可以用引用去初始化引用

    int in=10;
    static int sint=in;


    // printf("size of a is :%zd\n",sizeof(a));
    // printf("size of b is :%zd\n",sizeof(b));
    // a=b;
    // printf("size of a is :%zd\n",sizeof(b));
    a.f(3);
    b.f(3);
   

    return 0;
}






/*
造型和类型转换到区别

*/