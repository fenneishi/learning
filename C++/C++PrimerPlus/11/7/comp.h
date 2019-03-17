
#if !defined(COMP_H_)
#define COMP_H_

#include<iostream>
using namespace std;


class Comp
{
private:
    double magic;
    double real;
public:
    Comp();
    Comp(double,double);
    friend Comp operator+(const Comp &,const Comp &);//返回值到底设计成引用好呢？还是非引用好呢？
    friend Comp operator-(const Comp &,const Comp &);
    friend Comp operator*(const Comp &,const Comp &);
    friend Comp operator*(double,const Comp &);//如果顺序反了呢？
    Comp operator~();
    friend istream & operator>>(istream & is,Comp &c);
    friend ostream & operator<<(ostream & os,const Comp &c);
    ~Comp();
};





#endif // COMP_H_

