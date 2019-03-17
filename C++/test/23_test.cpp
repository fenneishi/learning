#include<stdio.h>
#include<iostream>
using namespace std;

class A
{
public:
    int i;
    double d;
    char a;
    A():i(1),d(1),a(65){cout<<"A:constructor"<<endl;}
};

class B :public A
{
};

int main(void)
{
    B b;
    cout<<"........"<<endl;
    A a;
    // int i(1);
    // double d(1);
    // char a(65);
    cout<<"........"<<endl;
    cout<<a.i<<endl;
    cout<<a.d<<endl;
    cout<<a.a<<endl;


    return 0;
}


/*
编译器提供的默认析构函数，干的活就是调用每个成员变量的默认析构函数（成员变量如果没有就会出错）
基本数据类型的默认析构函数，基本上就是啥事不干，情况下大多数也不会给你初始化为0。
（因为编译器认为反正你要初始化，我多初始化一遍不是多此一举吗？）
但有特殊情况，例如全局变量，会自动初始化为0（地址为NULL，不同系统的NULL可能不同）
例如有些编译器的debug模式，会给你默认初始化为一个特殊的值。
*/