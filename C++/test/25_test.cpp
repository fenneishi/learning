#include <stdio.h>
#include <iostream>
using namespace std;

class A
{
  public:
    int i;
    double d;
    char a;
    A();
    A(int i,int j=0);
    ~A();
};

A::A() : i(1), d(1), a(65) { cout << "A:default_constructor" << endl; }
A::A(int i,int j) : i(i), d(j), a(i) { cout << "A:constructor" << endl; }
A::~A() { cout << "A:destructor" << endl; }

class B:public A
{
};

struct S{
    int a;
    int b;
};


int main(void)
{
    A a(1);
    A aa=1;
    A aaa={1};//only C11
    A aaaa{1};//only C11
    A *pa=new A(1);
    A *paa=new A{1};//only C11

    A ta(1,1);
    A taa=1;
    A taaa={1,1};//only C11
    A taaaa{1,1};//only C11
    A *tpa=new A(1,1);
    A *tpaa=new A{1,1};//only C11
    
    B b;
    B bb{};//only C11
    B bbb={};//only C11
    B bbbb=B();
    B *pb=new B;
    B *pbb=new B();
    B *pbbb=new(sizeof(B));//应该要经过某种强制类型转换才行

    return 0;
}

/*
以上列出一个没有参数（默认构造函数），一个参数、多个参数的情况
只有C11才支持类的初始化列表去初始化类。
至于结构的初始化情况，需要再去尝试
如果要使得按照C11标准编译，一定加上-std=c++0x。

*/