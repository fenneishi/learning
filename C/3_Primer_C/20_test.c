#include<stdio.h>
struct rect{
    int a;
    int b;
};
int global_a;
struct rect *globl_p_rect=&(struct rect){1,2};
// char *globl_p_rect="Hello";
int global_b;
int *global_p_a=&global_a;//虽然含有变量，但是因为编译时候能够知道值，所以可以用来初始化静态存储区变量。
int *global_p_b=&global_b;

struct rect * zimianliang(void);
int main(void)
{
    char *p=NULL;
    zimianliang();
   
    return 0;
}


struct rect * zimianliang(void)
{
    char a=0;
    char *p="hello";

    printf("a         =>%p\n",&a);
    printf("hello     =>%p\n",p);
    printf("rect      =>%p",&(struct rect){1,2});
    printf("==============================\n");
    printf("global_p_a=>%p\n",global_p_a);
    printf("global_p_r=>%p\n",globl_p_rect);
    printf("global_p_b=>%p\n",global_p_b);

    return &(struct rect){1,2};
}


/*

字面量的存储位置探寻？

复合字面量有一个生成临时变量过程，
你写的代码：struct rect rec=(struct rect){1,2};
实际编译器翻译的代码：
struct rect linshi=(struct rect){1,2};
struct rect rec=linshi;

你写的代码：struct rect *p=&(struct rect){1,2};
实际编译翻译的代码：
struct rect linshi=(struct rect){1,2};
struct rect *p=&linshi;
所以复合字面量既不是变量也不是常量
常量：无论出现在哪里，存储位置都在代码区，但是复合字面量存储位置在数据区（静态区或栈）
变量：编译时候是无法知道其值的，但是复合字面编译时候是知道的，因为可以用复合字面量去初始化静态去变量
注：
1、能否初始化静态区变量，关键看是否是编译时常量，或者说编译时知道大小的量。
2、要注意编译器编译时是一句一句的，而且并不会记录上一句干了什么，更不会记录下来每个变量当下的数值是多少。
但是struct rect rec=(struct rect){1,2};是一句话，这就话内，编译器创建了一个结构变量linshi，并给结构变量赋了值，再把这个变量的值付给了结构变量rec,由于再一句话之内，所以编译器是可以记得结构变量linshi的值的。


*/