#include"cd.h"
#include<cstring>
#include<iostream>
using namespace std;
Cd::Cd(const char* per,const char *lab,int sel,double plti)
{
    // 暂时未考虑给定字符串过长的问题
    strcpy(performers,per);
    strcpy(label,lab);
    selections=sel;
    playtime=plti;
}
// Cd::Cd(const Cd & cd)
// {

// }
Cd::Cd()
{
    strcpy(performers,"default");
    strcpy(label,"default");
    selections=0;
    playtime=0;
}
Cd& Cd::operator=(const Cd &d)
{
    if(this==&d)
        return *this;
    else    
        strcpy(performers,d.performers);
        strcpy(label,d.label);
        selections=d.selections;
        playtime=d.playtime;
    return *this;
}
Cd::~Cd()
{

}
void Cd::report() const
{
    cout<<"reports all CD data"<<endl;
}