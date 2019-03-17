
#include "person.h"
#include <string.h>
#include <iostream>
using namespace std;

Person::Person(const string &ln, const char *fn)
{
    lname = ln;
    if (sizeof(fn) <= Person::LIMIT)
        strcpy(fname, fn);
    else
        cout << "Person's first name is too long!" << endl;
}

void Person::show() const
{
    cout<<"----------------"<<endl;
    cout<<"first name:"<<fname<<endl;
    cout<<"last name :"<<lname<<endl;
    cout<<"++++++++++++++++"<<endl;
}
void Person::FormalShow() const
{
    cout<<"----------------"<<endl;
    cout<<"last name :"<<lname<<endl;
    cout<<"first name:"<<fname<<endl;
    cout<<"++++++++++++++++"<<endl;
}