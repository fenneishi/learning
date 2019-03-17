# include "vintageport.h"



Vintageport::Vintageport():Port()
{
    nickname=new char[10];
    strcpy(nickname,"default");
    year=0;
}
Vintageport::~Vintageport()//析构函数只要操心当系统把自己管理的这篇内存区域删除的时候，会有什么问题(主要问题就是辖区内有个内存管理者）
{
    delete[] nickname;
}
Vintageport::Vintageport(const Vintageport & vp):Port(vp)//上头的辖区，交个上头去管，你只需给以材料就行(材料内容多一点没关系，只要前几章是人家上头要的就成)
{
    nickname=new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    year=vp.year;
}
Vintageport& Vintageport::operator=(const Vintageport &vp)//相比拷贝构造多了一个判断和打扫屋子
{
    if(this==&vp)
        return *this;
    else
        Port::operator=(vp);//同样，上头的辖区交给上头去管，你把材料给人家就行。
        delete[] nickname;//先打扫屋子
        nickname=new char[strlen(vp.nickname)+1];
        strcpy(nickname,vp.nickname);
        year=vp.year;
        return *this;  
}
Vintageport::Vintageport(char *nn):Port()
{
    nickname=new char[strlen(nn)+1];
    strcpy(nickname,nn);
    year=0;
}
Vintageport::Vintageport(char *nn,int y):Port()
{
    nickname=new char[strlen(nn)+1];
    strcpy(nickname,nn);
    year=y;
}
Vintageport::Vintageport(char *nn,int y,const char *br,const char *st,int bo):Port(br,st,bo)
{
    nickname=new char[strlen(nn)+1];
    strcpy(nickname,nn);
    year=y;
}
ostream& operator<<(ostream &os,const Vintageport p)//是友元函数，所以无法直接通过作用域解析符指出要使用哪个函数。
{
    os<<(const Port)p<<" "<<p.nickname<<" "<<p.year;
    return os;
}
istream& operator>>(istream &is,Vintageport p)
{
    is>>(const Port)p;
    cout<<"nickname:";(is>>p.nickname).get();
    cout<<"year:";(is>>p.year).get();
    return is;
}

void Vintageport::show()const
{
    Port::show();//相当于(*this).(Port::show())，你加了域限定，只能调用父类的函数了，虽然this指向的是子类，而且是虚函数。
    cout<<"nickename: "<<nickname<<endl;
    cout<<"year:"<<year<<endl;
}



