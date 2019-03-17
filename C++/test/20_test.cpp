#include<stdio.h>
#include<iostream>
using namespace std;

class A 
{

};
void f(A a)
{

}
int main(void)
{
    A a;
    A &ra=a;
    A &Ra=ra;
    A aa=ra;
    f(a);
    f(ra);
    f(Ra); 

    return 0;
}

