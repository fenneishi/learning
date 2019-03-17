#include<stdio.h>

class test
{
public:
    int a;
    void f1(void)
    {
        printf("%d\n",a);
    }
    void f2(void)
    {
        a=2;
        f1();
    }

};



int main(void)
{
    test t;
    t.a=1;
    t.f1();
    return 0;
}




/*
一个变量集合（结构）和一个函数集合 共用了一个名字。
*/