#include<stdio.h>
#include<iostream>
using namespace std;

class A
{
    int a;
public:
    A(int i):a(i){cout<<"A():constructor"<<endl;};
    A():a(1){cout<<"A():default_  constructor"<<endl;};
};

class B:public A
{
    int b;
public:
    B(int i):A(i),b(i){cout<<"B():constructor"<<endl;}
    B(){};
};

class C:public A
{
    B b;
public:
    C(B bb):b(bb){cout<<"C():constructor"<<endl;};
    operator B() const{return b;};
};
//#1和#2函数同时存在，编译器并不会报错，但是执行时可能会遇到ambiguous错误
// void f(A &a);//#1 
// void f(A a);//#2
void f(B b);//#3
// void f(C c);//#4
// slicing 
int main(void)
{
    A a(1);
    f(1);
    
    // B b(1,2);
    // cout<<"......"<<endl;
    // C c(b);
    // C &cc=c;
    // cout<<"f(c)"<<endl;
    // f(c);
    /*
    void f(A &a);//#1:发生创建临时变量+Upcast
    void f(A a) ;//#2:发生slicing 
    void f(B b) ;//#3:发生Implict Conversation(User-defined Conversation)
    void f(C c) ;//#4:exact的一种(实参和形参完全一致)
    */
    // cout<<"f(cc)"<<endl;
    // f(cc);
    /*
    void f(A &a);//#1:发生Upcast（没有创建临时变量）
    void f(A a) ;//#2:发生Trivial Conversation(C的对象引用到C的对象)+slicing 
    void f(B b) ;//#3:发生Implict Conversation(User-defined Conversation)
    void f(C c) ;//#4:exact的一种(实参和形参完全一致)
    */


    return 0;
}

void f(A &a)
{
    printf("this is f(A a)\n");
    printf("the size of a is %zd\n",sizeof(a));
};


void f(B  b)
{
    printf("this is f(B b)\n");
    printf("the size of b is %zd\n",sizeof(b));
};

void f(C c)
{
    printf("this is f(C c)\n");
    printf("the size of c is %zd\n",sizeof(c));
};

/*
1、到底调用那个condate function：最匹配
    1、condate function list 形成：所有可行函数（包含魔板生成的）
    2、select the best function from list：一套规则
2、调用过程发生了什么：stack模型
    1、要领：大小一致：通过实参往stack放的数据必须要和对应形参规定的数据大小一致，
    2、地址：（包含指针和引用）本身所有地址大小就是一致的，关键是指针指向的类型，
            这个类型决定函数内部的使用不合规时候能否检测到（被编译器），所以地址的类型必须要一致，
            或者至少能够成upcast关系，强制转换属于一致的情况。
    3、非地址型对象：必须要类型一致，类型一直才能绝对保证大小一致，顺便也能保证不安全使用能查出（函数内部）
                  类型不一致就会发生类型转换，conversation有三种：Trivial、sicing、implict
                  1、condate function list中，四者的匹配度的高低关系是：Trivial>slicing=uncast>implict
                  2、某一个具体函数调用实参到形参的传递过程中，可能同时发生四种情况，取最低值：
                    1、同时发生Trivial和slicing：那么这个过程被定义为slicing.
                    2、同时发生Trivial和upcast:那么这个过程被定义为upcast.
                  3、形参是引用时候，有时会发生产生一个临时对象的情况，产生临时对象并不影响匹配度高低。
3、总结：s
1、所有过程刨根问底就是参数传递
2、参数传递会发生4+1（也可以说成3+1+1）：Trivial>slicing=upcast>implict + 临时对象
3、参数传递的本质是大小一致+函数内部错误使用能被编译捕获 这两个条件。
*/