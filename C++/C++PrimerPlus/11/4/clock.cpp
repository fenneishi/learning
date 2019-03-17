
#include "time.h"

void Time::reset(int h,int m)
{
    _h=h;
    _m=m;
}


void Time::addHour(int h)
{
    _h+=h;
}
void Time::addMine(int m)
{
    _m+=m;
    _h+=_m/60;
    _m%=60;
}

Time operator+(const Time &c1,const Time &c2)
{
    Time sum;
    sum._m=c1._m+c2._m;
    sum._h=c1._h+c2._h+sum._m/60;
    sum._m%=60;
    return sum;
}
Time operator-(const Time &c1,const Time &c2)
{
    Time diff;
    int diffm=(c1._h*60+c1._m)-(c2._h*60+c2._m);
    diff._h=diffm/60;
    diff._m=(diffm%60);
    return diff;
}
std::istream & operator>>(std::istream &is, Time &c)
{
    is>>c._h;
    is>>c._m;
    return is;
}
std::ostream & operator<<(std::ostream &os, const Time &c)
{
    os<<"(h,m)="<<"("<<c._h<<":"<<c._m<<")";
    return os;
}