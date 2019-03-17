#include"cd.h"
#include<cstring>
#include<iostream>
using namespace std;
Cd::Cd(const char* per,const char *lab,int sel,double plti)
{
    performers=new char[strlen(per)+1];
    strcpy(performers,per);

    label=new char[strlen(lab)+1];
    strcpy(label,lab);

    selections=sel;
    playtime=plti;
}
Cd::Cd(const Cd & d)
{
    performers=new char[strlen(d.performers)+1]; 
    label=new char[strlen(d.label)+1];
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
}
Cd::Cd()
{
    performers=new char[10];
    label=new char[10];
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
        delete[] performers;
        delete[] label;
        performers=new char[strlen(d.performers)+1]; 
        label=new char[strlen(d.label)+1];
        strcpy(performers,d.performers);
        strcpy(label,d.label);
        selections=d.selections;
        playtime=d.playtime;
    return *this;
}
Cd::~Cd()
{
    delete[] performers;
    delete[] label;
}
void Cd::report() const
{
    cout<<"reports all CD data"<<endl;
}