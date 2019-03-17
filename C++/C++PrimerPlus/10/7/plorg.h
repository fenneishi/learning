#ifndef PLORG_H_
#define PLORG_H_
# include <iostream>
# include <string.h>


class Plorg
{
private:
    enum{MAX=19};
    char _name[MAX];
    int _id;
public:
    // Plorg(char name[]="Plorga", int id=50):_id(id){std::strcpy(_name,name);}
    // conversison from string literal to 'char *' is deprecated
    Plorg(char name[]=(char *)"Plorga", int id=50):_id(id){std::strcpy(_name,name);}
    // Plorg(char name[]=NULL, int id=50):_id(id){
    //     if(name==NULL) std::strcpy(_name,"Plorga");return;
    //     std::strcpy(_name,name);
    // }
    void changeID(int newID){_id=newID;}
    void show(){std::cout<<"name:"<<_name<<"  "<<"id:"<<_id<<std::endl;}
    ~Plorg() { }
};




#endif