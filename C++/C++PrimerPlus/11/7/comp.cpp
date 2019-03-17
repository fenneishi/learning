

#include "comp.h"

Comp::Comp():magic(0),real(0){}
Comp::Comp(double mag,double rea):magic(mag),real(rea){}
Comp operator+(const Comp &a,const Comp &b)
{
    Comp res;
    res.real=a.real+b.real;
    res.magic=a.magic+b.magic;
    return res;
}
Comp operator-(const Comp &a,const Comp &b)
{
    Comp res;
    res.real=a.real-b.real;
    res.magic=a.magic-b.magic;
    return res;
}
Comp operator*(const Comp &a,const Comp &b)
{
    Comp res;
    res.real=a.real*b.real-a.magic*b.magic;
    res.magic=a.real*b.real+a.magic*b.magic;
    return res;
}
Comp operator*(double n,const Comp & c)
{
    Comp res;
    res.real=c.real*n;
    res.magic=c.magic*n;
    return res;
}
Comp Comp::operator~()
{
    Comp res;
    res.real=real;
    res.magic=-magic;
    return res;
}

istream & operator>>(istream & is,Comp &c)
{
    cout<<"please intput the real number:";
    is>>c.real;
    cout<<"please intput the magc number:";
    is>>c.magic;
    return is;
}
ostream & operator<<(ostream & os,const Comp &c)
{
    if(c.magic>0)os<<c.real<<"+"<<c.magic<<"i";
    else if(c.magic<0)os<<c.real<<c.magic<<"i";
    else os<<c.real<<"+"<<0<<"i";
    return os;
}


Comp::~Comp(){}