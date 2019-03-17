#include<stdio.h>

struct  test
{
public:
    int a;
};


void print_test(test *self);
int main(void)
{
    test t;
    t.a=1;
    print_test(&t);
    return 0;
}

void print_test(test *self)
{
    printf("%d\n",(*self).a);
}




/*
有些语法规则和难点是解构过程
有些是解构之后的C语言部分，
要区分清楚，这些规则是哪个阶段的，才能充分理解。

*/