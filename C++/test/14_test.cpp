#include<stdio.h>


class T
{
public:
    int a;
    int b;
    void f1(void);
    void f2(void);
};



int main(void)
{
    T t;
    t.a=1;
    t.b=2;
    t.f1();
    t.f2();
    return 0;
}

void T::f1(void)
{
    printf("%d\n",a);
}

void T::f2(void)
{
    printf("%d\n",b);
}




/*
原始C++写法
*/