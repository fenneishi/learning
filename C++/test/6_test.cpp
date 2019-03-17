#include<stdio.h>
int a;
class test
{
public:
    int a;
    test();
    virtual ~test();
    void print_test(int tt)
    {
        ::a=1;
        printf("%d\n",tt);
    }
};



int main(void)
{
    class test{
    public:
        int a;
        test();
        virtual ~test();
        void print_test(int tt)
        {
            ::a=1;
            printf("%d\n",tt);
        }
    };

    test t;
    t.a=1;
    t.print_test(1);
    return 0;
}

int m(void)
{
    t.a=1;
}


// void print_test(int tt)
// {
//     printf("%d\n",tt);
// }



/*
课件类大括号与函数大括号平级，且是两个体系
函数可以放到类里面，也可以和类平级。
类可以放到函数里面，也可以和函数平级。
但是
函数不能放到函数里面，只能平级
类不能放到类里面，只能平级

*/