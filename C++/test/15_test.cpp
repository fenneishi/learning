#include<stdio.h>

typedef struct
{
    int a;
    int b;
} T_Vari;
namespace T_Func
{
    void f1(T_Vari *t);
    void f2(T_Vari *t);
};



int main(void)
{
    T_Vari t;
    t.a=1;
    t.b=2;
    T_Func::f1(&t);
    T_Func::f2(&t);
    return 0;
}

void T_Func::f1(T_Vari *t)
{
    printf("%d\n",(*t).a);
}

void T_Func::f2(T_Vari *t)
{
    printf("%d\n",(*t).b);
}




/*
转换成C语言的写法
这里面可以看出几点理解：

1、类的名字的二重性：
    1、首先它是一个结构的名字（typedef）
    2、其次它是一些函数集合namespace的名字。
2、对象名.的二重性：
    1、对象名.成员变量名：t.a----->成员变量的标识。
    2、对象名.成员函数名：
        1、对象名起到了确定命名空间的作用：编译器查找小本本，根据对象的类型，进而确定调用哪个命名空间里面的函数。
        2、.起到了参数传递的作用，自动的把对象地址传递给函数的形参（this）


以上就是C++中类的封装特性的C语言拆解。
*/