# include "cow.h"

Cow::Cow():name()// 这种不加任何参数形式的默认初始化形式数组应该还是接受的。到底初始化我什么样子了？
{
    strcpy(name,"default");//不要不管name,否则在输出的时候麻烦！
    hobby=new char[10];
    strcpy(hobby,"default");//不要把hobby弄成指向nullptr，这样输出的时候麻烦
    weight=0;
    cout<<name<<"'s default construct was call!"<<endl;
}
Cow::Cow(const char *nm, const char *ho,double wt)
{
    //初始化name
    if(strlen(nm)<=19)strcpy(name,nm);
    else cout<<nm<<"  is too long ,must <20 charator!"<<endl;
    //初始化hobby
    hobby=new char[strlen(ho)+1];
    strcpy(hobby,ho);
    //初始化weight
    weight = wt;
    cout<<name<<"'s parameter construct was call!"<<endl;
}
Cow::Cow(const Cow &c)
{
    // name
    strcpy(name,c.name);//都是Cow对象，不用担心空间不够用
    // hobby
    hobby=new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    // weight
    weight=c.weight;
    cout<<name<<"'s copy construct was call!"<<endl;
}
Cow & Cow::operator=(const Cow &c)
{
    cout<<name<<"'s assignment function was call!"<<endl;
    // self to self
    if(this==&c)return *this;//因为c是const,所以这里只能是*this;
    // delete
    delete[] hobby;
    // depth copy
        // name
    strcpy(name,c.name);//都是Cow对象，不用担心空间不够用
        // hobby
    hobby=new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
        // weight
    weight=c.weight;
    return *this;
}
void Cow::showCow()const
{
    cout<<"name :"<<name<<endl;
    cout<<"hobby :"<<hobby<<endl;
    cout<<"weight :"<<weight<<endl;
}
Cow::~Cow()
{
    cout<<name<<"'s destruct was call!"<<endl; 
    delete[] hobby;
}