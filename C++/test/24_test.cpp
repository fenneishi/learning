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
    A(int i);
    ~A();
};

A::A() : i(1), d(1), a(65) { cout << "A:default_constructor" << endl; }
A::A(int i) : i(i), d(i), a(i) { cout << "A:constructor" << endl; }
A::~A() { cout << "A:destructor" << endl; }

class B:public A
{
};


int main(void)
{
{
    cout << A().i << endl;
    cout << "........................1" << endl;
    cout << A().d << endl;
    cout << "........................2" << endl;
    cout << A().a << endl;
    cout << "........................3" << endl;
    B();
    cout << "........................4" << endl;
    A(65);
    cout << "........................5" << endl;
    B *pb=new B();
    B *pbb=new B;
    A *pbbb=new A(1); 
    cout << "........................6" << endl;
    B bb=B();
}
    cout<<";;;;;;;;;;;"<<endl;

    A a(1);

    return 0;
}

/*
构造函数是相当于全局函数一样，直接在外部可以使用的.
单独调用构造函数的时候，会创造出一个临死对象，临时对象很快就被删除并且析构了。

程序执行结果如下：

longqi@longdeMacBook-Pro:~/Desktop/code/learn/7_C++/training$ ./24_test
A:default_constructor
1
A:destructor
........................
A:default_constructor
1
A:destructor
........................
A:default_constructor
A
A:destructor
........................
A:default_constructor
A:destructor
........................
A:constructor
A:destructor
........................
longqi@longdeMacBook-Pro:~/Desktop/code/learn/7_C++/training$

*/