#include<stdio.h>


class test
{
public:
    int a;
    void f1(int a)
    {
        printf("%d\n",a);
    }
    void f2(test *self)
    {
        f1((*self).a);
    }
 
};



int main(void)
{
    test t1;
    t1.a=1;
    test::f2(&t1);// 尽管不能这样用，但是实际上当C++代码翻译成C代码过程中，就是这样的。
    return 0;
}




/*

*/