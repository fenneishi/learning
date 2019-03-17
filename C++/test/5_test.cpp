#include<stdio.h>
int a;
class test
{
public:
    int a;
    test();
    virtual ~test();
    void print_test(int);
};

int t;
// int lll;

int main(void)
{
    test t;
    t.a=1;
    t.print_test(1);
    ::t=1;
    class ::a =1;
    int lll;
    {
        int lll;
        lll=1;
        ::lll=1;
        mian::lll=1;//?应该如何表达，只是想指定上一级别的，而不是全局的？
    }
    return 0;
}

int m(void)
{
    t.a=1;//课件t.a的作用域了
}


void print_tes(int tt)
{
    printf("%d\n",tt);
}

void test::print_test(int tt)
{
    ::a=1;
    ::print_test(3);
    printf("%d\n",tt);
}

/*
定义时：名字到底归属那个大括号
使用时：多个重名的时候到底使用哪一个？

默认方式
特殊指定的工具

变量名：
    定义时：定义在哪里，就属于哪里。
    使用时：
        默认：
            默认大括号内部可以调用（整个文件想象成一个大括号）
            大括号内部的大括号，如果重名，则自动隐藏。
        特殊指定工具：
            成员变量点.---->这个道理和结构很像，结构名哪里可以用，成员变量就哪里可以用，指针哪里可以用，p->成员变量就哪里可以用.
            这时候就要区分"结构名.成员变量名”的scope与成员变量名的scope的不同
            记住，scope机制本身是为了防止名字混乱，这是根本判断标准，只要不会混乱，就可以为。
函数名：同变量名

1、test::print_test---->把后面的括号的整体放倒test的括号内。
2、无论是变量名还是函数名，在哪个大括号内部定义的，可见范围或者说是scope范围就是大括号内部。
    1、注意：可以把整个文件当成一个大的括号。
    2、注意：暂时不考虑链接这样的东西。
    3、注意：暂时不考虑大括号的嵌套
3、t.print_test t.a与 t具有相同的scope
4、::lll----->缺省::lll----->全局::lll  使用的时候
5、test::print_test()----->(同一级别那个大括号内部的？必须要选一个)::print_test()  定义的时候


考虑大括号多层嵌套

*/