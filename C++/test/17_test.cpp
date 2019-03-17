#include<stdio.h>
#include<iostream>
using namespace std;
int g_a=10;
int g_b=10;

class A 
{
    double i;
public:
    A(double a):i(a){};
    void f(int i){
    }
};

class B 
{
public:
    static int i;
    // int i;不能和static重名，因为处于同一个namespace下面
    void f(int i){
        this->i=i;
    }
    void print_static(void);
};
int B::i=1;

void B::print_static(void)
{
    printf("the location of   i is %p\n",&i);//the location of   i is 0x10d351020
    printf("the location of   i is %p\n",&this->i);
};



int main(void)
{
   
    A a(1);
    B b;
    printf("size of a is %zd\n",sizeof(a));//size of a is 1
    printf("size of b is %zd\n",sizeof(b));//size of b is 1
    // 说明static根本就没有在每个对象都有一个副本，想想也不可能
    b.print_static();
    printf("the location of   a is %p\n",&a);
    printf("the location of   a is %p\n",&b);
    printf("the location of g_a is %p\n",&g_a);
    printf("the location of g_b is %p\n",&g_b);

    cout<<b.i<<endl;//静态成员遵循成员变量的访问规则
    cout<<B::i<<endl;//同时也遵循他本来的访问规则，当然如果是private的，也是不能访问的

    int aaa=9.0;


    return 0;
}






/*
静态成员变量的研究
size of a is 1
size of b is 1
the location of   i is 0x10d351020
the location of   i is 0x10d351020
the location of   a is 0x7ffee28af9b8
the location of   a is 0x7ffee28af9b0
the location of g_a is 0x10d351018
the location of g_b is 0x10d35101c
明显存在静态存储区

能用this->i访问，只能解释为C++专门设计了这个机制。

静态成员能够方便本类及子类所有成员进行信息交流。但是容易把耦合搞的太复杂了

静态的成员在你建立对象前，就可以访问
静态的成员可以不用.的形式去调用。
静态的成员函数只能访问静态的成员变量（因为就没有给你传递this指针）


赋值其实是参数传递，参数传递其实是初始化，
初始化有两种情况，每种情况又有两种方法：
情况一：一个参数的初始化
    方法一：A a(b);
    方法二：A a=b;调用的构造器( A::A(B&）)如果加了关键词explicit,则此方法失效。
    注意：
        1、构造器可以是：A::A(B&）或A::A(B） 
        2、初始化方式可以是：A a(b);或A a(b的引用);
        3、成员函数可以是：class A{B b;}或class A{B &b;}
        4、以上交叉的8种情况都是可以的，最终都会发生拷贝构造。
        5、以上8种情况，可能会发生多次B类对象和B类对象的引用的自动类型转换。
情况二：多个参数的初始化
    方法一：A a(b,c);
    方法二：A a={b,c};调用的构造器( A::A(B&,C&）)如果加了关键词explicit,则此方法失效。
    注意：
        1、多个参数时候，每个参数都会递归的发生一次构造，参数的构造函数里的参数又会把递归进行下去。
        2、直到最后发生都是基本数据类型间的拷贝构造或者是缺省构造结束。


所以无论哪种构造，最后发生的都是拷贝构造或缺省构造，这是一个递归的过程，所以C++会自动提供拷贝构造和缺省构造。
猜测：引用也是一个类，指针也会是一个类，
结论：B类对象可以用B类对象的引用进行拷贝构造，反之也行。


总结：

赋值是函数调用，函数调用关键是确定函数、拥有权限、参数传递
参数传递本质是第二种方法的对象构造。（形参的初始化发生在调用函数的时候）（使用explicit，第二种方法失效。）
对象构造的本质又是参数传递


*/