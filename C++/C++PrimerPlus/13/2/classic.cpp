
# include "cd.h"
# include "classic.h"
# include <cstring>
# include <iostream>
using namespace std;


Classic::Classic():Cd()
{
    str=new char[10];
    strcpy(str,"defalt");
}
Classic::Classic(const char *s,const char* per,const char *lab,int sel,double plti):Cd(per,lab,sel,plti)
{
    str=new char[strlen(s)+1];
    strcpy(str,s);
}

Classic::~Classic()
{
    delete[] str;
}

Classic& Classic::operator=(const Classic &d)
{
    if(this==&d)
        return *this;
    else
        Cd::operator=(d);
        delete[] str;
        str=new char[strlen(d.str)+1];
        strcpy(str,d.str);
        return *this;
}

void Classic::report()const
{
    cout<<"Clssic report!"<<endl;
}