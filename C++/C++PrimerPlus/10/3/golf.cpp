# include "golf.h"

int Golf::setGolf()//return 1 if name is entered;return 0 if is not
{
    string name;
    int handicap;
    cout<<"input name:";
    cin>>name;
    cout<<"input handicap";
    cin>>handicap;
    if(name.empty())return 0;
    *this=Golf(name,handicap);
    return 1;
}
void Golf::setHandicap(int handicap)//reset handicap to new value.
{
    _handicap=handicap;
}
void Golf::show()
{
    cout<<"name is :"<<_name<<endl;
    cout<<"handicap is :"<<_handicap<<endl;
}
