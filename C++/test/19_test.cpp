#include<stdio.h>
#include<iostream>
using namespace std;


class S
{

};

class D
{
public:
    operator S()const{return S();};
};


class B
{
    S s;
public:
    B(S ss):s(ss){};
};

class A
{
    B b;
public:
    A(B bb):b(bb){};
};
int  main(void)
{
    D d;
    A a(d);
    /*
    不能合作：
19_test.cpp:34:7: error: no matching constructor for initialization of 'A'
    A a(d);
      ^ ~
19_test.cpp:25:7: note: candidate constructor (the implicit copy constructor) not viable: no known conversion from 'D' to 'const A' for 1st
      argument
class A
      ^
19_test.cpp:29:5: note: candidate constructor not viable: no known conversion from 'D' to 'B' for 1st argument
    A(B bb):b(bb){};
    ^
1 error generated.
    */
    return 0;
}





/*


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


函数调用-参数构造体系

类型转换体系


结合：

用哪种路径解决？
结合两种方法？
系统自带的自动类型转换
区别自动类型转换和cast.

c的基础上加上了两个维度：一切皆对象，一切皆函数


*/