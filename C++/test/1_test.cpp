#include<stdio.h>

class test
{
public:
    int a;
    test();
    virtual ~test();
    void print_test(int);
};



int main(void)
{
    test t;
    t.a=1;
    t.print_test(1);
    return 0;
}

void test::print_test(int tt)
{
    printf("%d\n",tt);
}

/*

*/